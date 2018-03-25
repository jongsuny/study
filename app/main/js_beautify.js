// node.js, "classic" way:
const beautify = require('js-beautify').html_beautify;


const jsOrigin = document.getElementById('jsOrigin');
const previewDiv = document.getElementById('jsBeautifiedView');
document.body.addEventListener('click', (event) => {
	console.log("test")
	// const pretty = js_beautify(jsOrigin.value, 4, " ")
	var config = {
        "eol": "\n",
        "end_with_newline": false,
        "preserve_newlines": true,
        "max_preserve_newlines": 1,
        "indent_inner_html": true,
        "brace_style": "none",
        "indent_scripts": "normal",
        "wrap_line_length": 0,
        "wrap_attributes": "auto"
    }
	const pretty = beautify(jsOrigin.value,config)
	console.log(pretty)
	previewDiv.value = pretty ;
})

previewDiv.addEventListener("scroll", (event, arg) => {
  const message = `Asynchronous message reply: ${arg}`
  console.log(message)
})
