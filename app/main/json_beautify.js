// node.js, "classic" way:
var sd = require('sweet-data');

const jsonOrigin = document.getElementById('jsonOrigin');
const previewDiv = document.getElementById('jsonBeautifiedView');
document.body.addEventListener('click', (event) => {

	sd.SweetData.json(jsonOrigin.value)
		.then(beautifiedJSON => previewDiv.value = beautifiedJSON)
		.catch(error => console.log(error));
	// const pretty = sd.SweetData.xml(xmlOrigin.value);
	// console.log(pretty)
	// previewDiv.value = pretty;
})

previewDiv.addEventListener("scroll", (event, arg) => {
	const message = `Asynchronous message reply: ${arg}`
	console.log(message)
})