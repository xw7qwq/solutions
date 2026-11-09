// 页面已经并入面板（lucius7.dev/oj/code/），这个站点只发布 data/ 里的快照。
// 旧链接带着查询参数和锚点跳到面板，例如 code.html?path=AtCoder/abc231/a.cpp；文档跳到 GitHub 上的 Markdown。
const { pathname, search, hash } = window.location;
const doc = pathname.match(/^\/docs(\/.*)?$/);
if (doc) {
  const page = (doc[1] || '/').replace(/\.html$/, '').replace(/\/$/, '/index');
  window.location.replace(`https://github.com/xw7qwq/solutions/blob/docs/project-guide/docs${page}.md`);
} else {
  window.location.replace(`https://lucius7.dev/oj/code/${search}${hash}`);
}
