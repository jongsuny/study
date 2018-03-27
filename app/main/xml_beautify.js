// node.js, "classic" way:
var sd = require('sweet-data');

const xmlOrigin = document.getElementById('xmlOrigin');
const previewDiv = document.getElementById('xmlBeautifiedView');
document.body.addEventListener('click', (event) => {

	sd.SweetData.xml(xmlOrigin.value)
		.then(beautifiedXML => previewDiv.value = beautifiedXML)
		.catch(error => console.log(error));
	// const pretty = sd.SweetData.xml(xmlOrigin.value);
	// console.log(pretty)
	// previewDiv.value = pretty;
})

previewDiv.addEventListener("scroll", (event, arg) => {
	const message = `Asynchronous message reply: ${arg}`
	console.log(message)
})