// node.js, "classic" way:
const htmlBeautify = require('js-beautify').html_beautify;

const htmlOrigin = document.getElementById('htmlOrigin');
const previewDiv = document.getElementById('htmlBeautifiedView');
document.body.addEventListener('click', (event) => {
    console.log("test")
    const pretty = htmlBeautify(htmlOrigin.value)
    console.log(pretty)
    previewDiv.value = pretty ;
})

previewDiv.addEventListener("scroll", (event, arg) => {
  const message = `Asynchronous message reply: ${arg}`
  console.log(message)
})
