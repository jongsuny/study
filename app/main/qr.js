var jrQrcode = require('jr-qrcode');

const qrInput = document.getElementById('qrInput');
const previewDiv = document.getElementById('qrPreview');
document.body.addEventListener('click', (event) => {
	var value = qrInput.value;
	if (value && value.trim() != "") {
		value = value.trim();
		if (value.length <= 10000) {
			var imgBase64 = jrQrcode.getQrBase64(value.trim());
			var img = '<img height="240" width="240" src="' + imgBase64 + '" />';
			previewDiv.innerHTML = img;
		} else {
			console.error("max length exceed! max: 10000");
		}
	}

})