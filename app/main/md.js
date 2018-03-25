// node.js, "classic" way:
var MarkdownIt = require('markdown-it');

var md = require('markdown-it')({
  html: true,
  linkify: true,
  typographer: true
});

const markdownEditor = document.getElementById('markdownEditor');
const previewDiv = document.getElementById('markdownPreview');
document.body.addEventListener('click', (event) => {
	console.log("test")
	var result = md.render(markdownEditor.value);
	console.log(result);
	previewDiv.innerHTML = result;

})

previewDiv.addEventListener("scroll", (event, arg) => {
  const message = `Asynchronous message reply: ${arg}`
  console.log(message)
})
