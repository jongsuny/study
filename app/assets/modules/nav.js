const settings = require('electron-settings')
document.body.addEventListener('click', (event) => {
	const cur = event.target;
	console.log(cur);
	if(!handleMenuClick(cur)) {
		handleMenuClick(cur.parentNode)
	}
})
document.querySelector("#collapse-menu").addEventListener('click', (event) => {
	const cur = document.body;
	if(cur.classList.contains("sidebar-collapse")) {
		cur.classList.remove("sidebar-collapse");
	} else {
		cur.classList.add("sidebar-collapse");
	}
})
function handleMenuClick(cur) {
	if(cur.tagName == "A" && cur.classList.contains("main_menu")) {
		handleMainMenu(cur);
		return true;
	} else if (cur.tagName == "A" && cur.classList.contains("sub_menu")) {
		handleSubMenu(cur);
		return true;
	}
	return false;
}
function handleMainMenu(cur) {
	const curLi = cur.parentNode;
	hideAllMainMenu();
	if(curLi.classList.contains("active")) {
		curLi.classList.remove("active");
		curLi.classList.remove("menu-open");
	}else {
		curLi.classList.add("active");
		curLi.classList.add("menu-open");
	}
	handleMenuItem(event);
}
function hideAllMainMenu(){
	const menus = document.querySelectorAll('li.treeview')
	Array.prototype.forEach.call(menus, (menu) => {
	  	menu.classList.remove("active");
		menu.classList.remove("menu-open");
	})
}
function handleSubMenu(cur) {
	hideAllSubMenu();
	const curLi = cur.parentNode;
	if(curLi.classList.contains("active")) {
		curLi.classList.remove("active");
	} else {
		curLi.classList.add("active");
	}
	handleMenuItem(event);
}
function hideAllSubMenu(){
	const menus = document.querySelectorAll('ul.treeview-menu li')
	Array.prototype.forEach.call(menus, (menu) => {
	  	menu.classList.remove("active");
	})
}
function handleMenuItem(event) {
	const cur = event.target;
	if(cur.dataset.template) {
		hideAllItem();
		const item = cur.dataset.template;
		const itemSection = document.getElementById(item);
		console.log(itemSection);
		itemSection.classList.remove("hidden");
	}
}
function hideAllItem() {
	const menus = document.querySelectorAll('section.sidebar a')
	Array.prototype.forEach.call(menus, (menu) => {
		if(menu.dataset.template) {
			const item = document.getElementById(menu.dataset.template);
			if(item) {
				item.classList.add("hidden");
			}
		}
	  	
	})
}
// document.body.addEventListener('click', (event) => {
//   if (event.target.dataset.section) {
//     handleSectionTrigger(event)
//   } else if (event.target.dataset.modal) {
//     handleModalTrigger(event)
//   } else if (event.target.classList.contains('modal-hide')) {
//     hideAllModals()
//   }
// })

// function handleSectionTrigger (event) {
//   hideAllSectionsAndDeselectButtons()

//   // Highlight clicked button and show view
//   event.target.classList.add('is-selected')

//   // Display the current section
//   const sectionId = `${event.target.dataset.section}-section`
//   document.getElementById(sectionId).classList.add('is-shown')

//   // Save currently active button in localStorage
//   const buttonId = event.target.getAttribute('id')
//   settings.set('activeSectionButtonId', buttonId)
// }

// function activateDefaultSection () {
//   document.getElementById('button-windows').click()
// }

// function showMainContent () {
//   document.querySelector('.js-nav').classList.add('is-shown')
//   document.querySelector('.js-content').classList.add('is-shown')
// }

// function handleModalTrigger (event) {
//   hideAllModals()
//   const modalId = `${event.target.dataset.modal}-modal`
//   document.getElementById(modalId).classList.add('is-shown')
// }

// function hideAllModals () {
//   const modals = document.querySelectorAll('.modal.is-shown')
//   Array.prototype.forEach.call(modals, (modal) => {
//     modal.classList.remove('is-shown')
//   })
//   showMainContent()
// }

// function hideAllSectionsAndDeselectButtons () {
//   const sections = document.querySelectorAll('.js-section.is-shown')
//   Array.prototype.forEach.call(sections, (section) => {
//     section.classList.remove('is-shown')
//   })

//   const buttons = document.querySelectorAll('.nav-button.is-selected')
//   Array.prototype.forEach.call(buttons, (button) => {
//     button.classList.remove('is-selected')
//   })
// } 

// function displayAbout () {
//   document.querySelector('#about-modal').classList.add('is-shown')
// }

// // Default to the view that was active the last time the app was open
// const sectionId = settings.get('activeSectionButtonId')
// if (sectionId) {
//   showMainContent()
//   const section = document.getElementById(sectionId)
//   if (section) section.click()
// } else {
//   activateDefaultSection()
//   displayAbout()
// }
