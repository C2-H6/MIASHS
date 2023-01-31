function naviguer(destination) {
	window.location.href = destination;
}

function changeTab(evt, target) {
	var tabcontent, tablinks;
	tabcontent = document.getElementsByClassName("tabcontent");
	for (let i = 0; i < tabcontent.length; i++) {
	  tabcontent[i].style.display = "none";
	}
	tablinks = document.getElementsByClassName("tablinks");
	for (let i = 0; i < tablinks.length; i++) {
	  tablinks[i].className = tablinks[i].className.replace(" active", "");
	}
	document.getElementById(target).style.display = "block";
	evt.currentTarget.className += " active";
  }

function creaCol(filename, directory, title) {
	var col = document.createElement("div");
	col.setAttribute("class", "column col-33");

	var card = document.createElement("card");
	card.setAttribute("class", "card");

	var img = document.createElement("img");
	img.setAttribute("class", "avatar");
	img.setAttribute("src", "img/" + filename + ".jpg");
	img.setAttribute("alt", filename);

	var container = document.createElement("div");
	container.setAttribute("class", "container");

	var h4 =  document.createElement("h4");
	var titleNode = document.createTextNode(title);
	h4.appendChild(titleNode);

	var button = document.createElement();
	button.setAttribute("class", "button primary")
	button.setAttribute("onclick", naviguer(directory + "/" + filename + ".html"));
	
	var btnText = document.createTextNode("Accéder");


	container.appendChild(h4);
	container.appendChild(button);

	card.appendChild(img);
	card.appendChild(container);

	col.appendChild(card);

	return col;
}

function populateTab(id, elements) 
{
	var row =  document.createElement("div");
	row.setAttribute("class", "row");

	for (let index = 0; index < array.length; index++) {
		const element = array[index];
		
	}
}


//  var series, films;