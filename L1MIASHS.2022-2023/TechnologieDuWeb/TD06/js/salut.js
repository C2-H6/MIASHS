function changeColor() {
	var salut = document.getElementById("salut");
	salut.style.color = "blue";
}

function addName() {
	var salut = document.getElementById("salut");
	var text = document.createTextNode("Salut Gaël 👋");
	salut.appendChild(text);
}