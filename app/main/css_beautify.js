// node.js, "classic" way:
const cssbeautify = require('js-beautify').css_beautify;

const cssOrigin = document.getElementById('cssOrigin');
const previewDiv = document.getElementById('cssBeautifiedView');
document.body.addEventListener('click', (event) => {
    console.log("test")
    const pretty = cssbeautify(cssOrigin.value)
    console.log(pretty)
    previewDiv.value = pretty ;
})

previewDiv.addEventListener("scroll", (event, arg) => {
  const message = `Asynchronous message reply: ${arg}`
  console.log(message)
})
