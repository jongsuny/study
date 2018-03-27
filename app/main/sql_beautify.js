// node.js, "classic" way:
var sd = require('sweet-data');

const sqlOrigin = document.getElementById('sqlOrigin');
const previewDiv = document.getElementById('sqlBeautifiedView');
document.body.addEventListener('click', (event) => {
    console.log("test")
    const pretty = sd.SweetData.sql(sqlOrigin.value);
    console.log(pretty)
    previewDiv.value = pretty ;
})

previewDiv.addEventListener("scroll", (event, arg) => {
  const message = `Asynchronous message reply: ${arg}`
  console.log(message)
})
