# solutions · gh-pages

本分支给[面板](https://lucius7.dev/oj/code/)发布题解索引快照，不再有自己的页面。题解搜索和源码阅读都在面板的 [/oj/code/](https://lucius7.dev/oj/code/)。

[面板](https://lucius7.dev/oj/code/) · [源码仓库](https://github.com/xw7qwq/solutions) · [文档](https://github.com/xw7qwq/solutions/tree/docs/project-guide/docs) · [反馈问题](https://github.com/xw7qwq/solutions/issues)

## 发布的内容

| 地址 | 内容 | 谁在读 |
| --- | --- | --- |
| [data/site-data.json](https://codeflare.lucius7.dev/data/site-data.json) | 题目列表和每个文件的提交时间，约 700 KB | 面板的 `/oj/code/`，精简成索引后在边缘缓存一小时 |
| [data/recent-commits.json](https://codeflare.lucius7.dev/data/recent-commits.json) | `main` 最近六次提交 | 面板目前不读，保留给已有的接口用户 |

源码正文由面板直接从 `main` 分支的 raw.githubusercontent.com 地址读取，不经过本分支。

旧地址都会跳走，查询参数和锚点保持不变：

- 首页和 `code.html?path=AtCoder/abc231/a.cpp` 这样的阅读链接跳到面板的 `/oj/code/`。
- `/docs/` 下的旧文档链接跳到 `docs/project-guide` 分支里对应的 Markdown。接口契约 `docs/api/openapi.json`、`site-data.schema.json` 和 `recent-commits.schema.json` 原样保留在原地址，它们的 `$id` 和 `servers` 指向这里。
- 其他路径由 `404.html` 跳到面板。

## 分支职责

| 分支 | 内容与修改入口 |
| --- | --- |
| [`main`](https://github.com/xw7qwq/solutions/tree/main) | 算法源码、模板与开发工具 |
| [`gh-pages`](https://github.com/xw7qwq/solutions/tree/gh-pages) | 本分支：数据快照、生成和发布脚本、旧地址跳转 |
| [`docs/project-guide`](https://github.com/xw7qwq/solutions/tree/docs/project-guide) | 文档 Markdown 和 API 契约 |

不要将其他分支整体合入本分支。

## 目录结构

| 路径 | 用途 |
| --- | --- |
| [index.html](index.html)、[code.html](code.html)、[404.html](404.html)、[panel-redirect.js](panel-redirect.js) | 旧地址跳转 |
| [data/](data/) | 两份 JSON 快照 |
| [docs/api/](docs/api/) | 快照的 OpenAPI 和 JSON Schema 契约，源文件在 `docs/project-guide` 分支的 `site/public/api/` |
| [scripts/generate-data.mjs](scripts/generate-data.mjs) | 从 `main` 的 Git 历史生成快照 |
| [scripts/publish-data.mjs](scripts/publish-data.mjs) | 推送快照并等 Pages 部署生效 |
| [scripts/tests/](scripts/tests/) | 发布脚本的回归测试 |
| [CNAME](CNAME)、[.nojekyll](.nojekyll) | GitHub Pages 自定义域名与静态文件发布配置 |

## 维护与校验

`main` 上的 **Site snapshots** 工作流在源码变更后和每天一次刷新两份快照，也可以手动运行。它取完整的 `main` 历史，生成并检查快照，然后只把 `data/` 下的两份 JSON 发布到本分支。被更新的 `main` 提交取代的构建会跳过。

发布脚本先核对仓库、检出分支、Pages 来源和自定义域名。用 `GITHUB_TOKEN` 推送后，它显式请求一次 Pages 构建，等两份快照的 blob 和线上 JSON 内容都一致才算成功。GitHub 替换了被取消的构建时，它在同一个轮询窗口里等替换后的构建。持续的构建失败、超时、推送失败或线上内容不一致都会让工作流失败。

指向 `gh-pages` 的 Pull Request 和本分支上的推送会运行 `check`：检查跳转脚本和发布脚本，运行回归测试，并在本地重新生成快照（不发布）。

本地刷新快照会覆盖 `data/` 下的两份 JSON，需要完整的 `main` 历史：

```sh
git fetch origin main
node scripts/generate-data.mjs origin/main
```

省略参数时生成器读取本地 `main`。浅克隆需先补齐历史，以免提交数量和时间不完整。

改动脚本后运行：

```sh
node --check panel-redirect.js
node --check scripts/generate-data.mjs
node --check scripts/publish-data.mjs
node --test scripts/tests/*.test.mjs
git diff --check
```

## 域名

快照发布在 **codeflare.lucius7.dev**。GitHub Pages 的发布来源是本分支根目录，根目录 [CNAME](CNAME) 保存自定义域名。面板通过 `SOLUTIONS_DATA_BASE` 读取 `https://codeflare.lucius7.dev/data`，换域名时要一起改。

DNS CNAME 指向 `xw7qwq.github.io`；仓库的 **Settings → Pages → Custom domain** 设为 `codeflare.lucius7.dev`，证书签发后开启 **Enforce HTTPS**。

## 贡献与许可

脚本改动以 `gh-pages` 为基线提交 Pull Request；算法源码提交到 `main`，文档提交到 `docs/project-guide`。详细规范见[贡献指南](https://github.com/xw7qwq/solutions/blob/docs/project-guide/CONTRIBUTING.md)。

仓库目前未声明统一的开源许可证。
