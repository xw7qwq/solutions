# GitHub Pages 维护

旧的根题库和阅读页已经并入[面板](https://lucius7.dev/oj/code/)。`gh-pages` 现在只发布面板读取的两份数据快照、快照 API 契约的发布副本，以及把旧地址转到面板的跳转页。文档不再发布成网站，直接在 GitHub 上阅读本分支的 Markdown。

## 分支与发布边界

| 分支 | 职责 | 更新后影响 |
| --- | --- | --- |
| `main` | OJ source archive and snapshot workflow | Pushes regenerate and publish both JSON snapshots |
| `gh-pages` | 数据快照、API 契约副本、旧地址跳转 | GitHub Pages 发布来源，目录为 `/(root)` |
| `docs/project-guide` | 文档源与 API 契约源文件 | 只做校验和构建，不发布；无需向 main 推送 |

不要把 main 或文档分支整体合入 gh-pages。跳转页和发布脚本的修改基于 gh-pages；文档修改基于 docs/project-guide。

The `Site snapshots` workflow on main generates `data/site-data.json` and `data/recent-commits.json` from the current `origin/main` after main pushes, daily schedules, and manual **Run workflow** runs. PRs targeting main validate the current main snapshots and the publication scripts without publishing. The generation job uploads both verified JSON files; the publishing job commits only those two files, explicitly requests a Pages build, and verifies the public JSON. It uses `queue: max` to preserve pending jobs; superseded main snapshots skip publication.

## 文件

路径相对于 gh-pages 根目录：

```text
index.html、code.html、404.html  旧地址跳转页
panel-redirect.js             跳到面板 /oj/code/，保留查询参数和锚点；/docs/ 下的旧链接跳到本分支的 Markdown
data/site-data.json           题库快照，保留旧统计字段
data/recent-commits.json      最近六次提交快照
docs/api/                     OpenAPI 与 JSON Schema 契约的发布副本
scripts/generate-data.mjs     从 Git 文件树和历史生成两份快照
scripts/publish-data.mjs      只发布两份快照，并核对 Pages 与公开 JSON
.nojekyll、CNAME              直接提供静态文件；自定义域名
```

`docs/api/` 下的文件是契约的 `$id` 和 `servers` 指向的地址。修改本分支 `site/public/api/` 中的契约后，通过指向 gh-pages 的 PR 把同一份文件复制过去，没有流程会自动发布它们。

## 面板如何读取

面板的 Worker 读取 `site-data.json`，精简成索引后在边缘缓存一小时；源码正文按路径从 main 分支的 raw.githubusercontent.com 地址读取。面板的 `/oj/code/?path=...` 与旧阅读页的 `code.html?path=...` 使用同一个路径参数，所以旧链接跳转后打开的是同一份源码。

## 生成快照

需要 Git 和 Node.js（建议受支持的 LTS）。保留完整 Git 历史，示例工作目录应尚不存在：

```bash
git fetch origin main gh-pages
git worktree add --detach ../codeflare-pages origin/gh-pages
cd ../codeflare-pages
git switch -c pages/update-snapshot
node scripts/generate-data.mjs origin/main
```

省略生成器参数时读取本地 main；建议使用刚获取的 origin/main。参数不会改变源码链接中的 main 分支。浅克隆先补齐历史，否则提交数量和时间不完整。

生成器写入两份 JSON。题库的 `commitCount`、`contributions` 继续生成以兼容旧契约；`ratings` 仅保留已有历史值，未知时为 null，不再请求 Rating 服务。文件提交时间是生成器遍历 Git 历史时记录的每个路径首次遇到的 `%cI`（提交者时间），不是 OJ 评测时间。

## 路径解析与完整性

生成器的 `problemFromPath` 决定哪些文件进入快照，新增 OJ 或改路径时检查这份规则：

- 子目录内支持 cpp、cc、cxx、c、py、java、rs、go、kt；第一段作为平台。
- 排除 Templates、.cph、.vscode、.github、assets、data、scripts；根目录独立源码不收录。
- 部分平台只能推导比赛页或平台首页，不保证每条均为精确原题地址。
- 未排除的新目录也可能被当作 OJ，需核对实际语义。

旧生成器没有用 NUL 分隔 Git 文件树，导致中文等非 ASCII 路径转义后漏收。现改用 `git ls-tree -r -z --name-only`。对 main 的 `7cca2a6` 核对：新快照和真实可识别路径均为 **1,291** 条，全部有提交日期；旧快照为 1,257 条。补齐的 34 条分布为 HDU 4、L7OJ 27、NowCoder 3。该数量是此提交的核对记录，不是契约固定值。

## 校验与发布

```bash
node --check panel-redirect.js
node --check scripts/generate-data.mjs
node --check scripts/publish-data.mjs
node --test scripts/tests/*.test.mjs
git diff --check
```

Both JSON files must pass [API validation](api/standards.md). Publish changes to the redirect pages or the scripts through PRs targeting gh-pages. Snapshots normally need no manual commit: `Site snapshots` generates them after main pushes, and can be rerun manually from main when needed. Publish documentation and contract changes through PRs targeting docs/project-guide. When adding a data endpoint, publish its data files before running documentation checks that depend on the remote snapshots.

```bash
gh api repos/xw7qwq/solutions/pages --jq '{status,source,https_enforced,html_url}'
gh api repos/xw7qwq/solutions/pages/builds/latest --jq '{status,commit,error}'
curl --fail --head https://codeflare.lucius7.dev/data/site-data.json
```

构建成功后核对公开 JSON 与预期版本，不能把本地语法检查当作已上线。

## 常见故障

| 现象 | 处理 |
| --- | --- |
| 面板里没有新题目 | 检查 main 路径和排除规则，再看 main 的 `Site snapshots` 是否发布成功；面板的索引最多缓存一小时 |
| File dates are unknown or stale | Inspect main's `Site snapshots` generation, publication, Pages, and public JSON checks; fix a failed run and rerun it manually from main |
| 旧链接没有跳转 | 核对 Pages 构建的提交，以及 `panel-redirect.js` 是否随同一次构建发布 |
