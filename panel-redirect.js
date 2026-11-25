// 页面已经并入面板（panel.lucius7.dev/oj/code/），这个站点只发布 data/ 里的快照。
// 旧链接带着查询参数和锚点跳到面板，例如 code.html?path=AtCoder/abc231/a.cpp；文档跳到 GitHub 上的 Markdown。
const { pathname, search, hash } = window.location;
const doc = pathname.match(/^\/docs(\/.*)?$/);
if (doc) {
  const page = (doc[1] || '/').replace(/\.html$/, '').replace(/\/$/, '/index');
  // 文档站有三页不是由 docs/ 下的同名文件生成的。
  const source = { '/repository': 'README', '/contributing': 'CONTRIBUTING', '/handbook': 'docs/README' }[page] || `docs${page}`;
  window.location.replace(`https://github.com/xw7qwq/solutions/blob/docs/project-guide/${source}.md${hash}`);
} else {
  window.location.replace(`https://panel.lucius7.dev/oj/code/${search}${hash}`);
}
