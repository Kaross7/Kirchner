function openPopup(popupId) {
    var popup = document.getElementById(popupId);
    var overlay = document.getElementById('overlay');
    closeAllPopups();
    closeHelp();
    popup.style.display = 'block';
    overlay.style.display = 'block';

    // Controleer of popup3 wordt geopend, en leeg popup1 als dat zo is
    if (popupId === 'popup3') {
        clearPopup1();
    }

    displayMessages(); // Toon berichten wanneer de popup opent
}

function displayInPopup1(message) {
    var messageDisplay = document.getElementById('selectedMessage');
    messageDisplay.textContent = message;
    saveToLocalStorage(message);
}
function loadPlanningFromServer() {
    fetch('/planning')
        .then(response => response.json())
        .then(data => {
            document.getElementById('selectedMessage').textContent = data.planning.content;
        })
        .catch(error => console.error('Error loading the planning:', error));
}

function savePlanningToServer(planningText) {
    fetch('/planning/update', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
            'X-CSRF-TOKEN': document.querySelector('meta[name="csrf-token"]').getAttribute('content')
        },
        body: JSON.stringify({content: planningText})
    })
    .then(response => response.json())
    .then(data => {
        console.log('Planning updated:', data);
    })
    .catch(error => console.error('Error updating the planning:', error));
}

function updatePlanning() {
    const planningContent = document.getElementById('selectedMessage').textContent;

    fetch('/planning/update', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
            'X-CSRF-TOKEN': document.querySelector('meta[name="csrf-token"]').getAttribute('content')
        },
        body: JSON.stringify({ content: planningContent })
    })
    .then(response => {
        if (response.ok) {
            return response.json();
        }
        throw new Error('Something went wrong on the server.');
    })
    .then(data => {
        console.log('Success:', data);
        alert('Planning updated successfully!');
    })
    .catch(error => {
        console.error('Error:', error);
    });
}







function clearPopup1() {
    var messageDisplay = document.getElementById('selectedMessage');
    if (messageDisplay) {
        messageDisplay.textContent = 'Geen bericht geselecteerd.'; // Maak de tekst leeg
    }
}

 
function closePopup(popupId) {
    var popup = document.getElementById(popupId);
    var overlay = document.getElementById('overlay');
    popup.style.display = 'none';
    overlay.style.display = 'none';
}
 
function toggleMenu(menuId) {
    var menu = document.getElementById(menuId);
    var menus = document.querySelectorAll('.dropdown-content');
    var buttons = document.querySelectorAll('.dropbtn');
    var container = document.querySelector('.container');
 
    menus.forEach(function(item) {
        if (item.id !== menuId) {
            item.style.display = 'none';
        }
    });
 
    if (menu.style.display === "block") {
        menu.style.display = "none";
        // Reset de positie van de knoppen
        buttons.forEach(function(btn) {
            btn.style.transform = 'translateY(0px)';
        });
    } else {
        menus.forEach(function(item) {
            item.style.display = 'none';
        });
        menu.style.display = "block";
 
        // Reset de positie van alle knoppen
        buttons.forEach(function(btn) {
            btn.style.transform = 'translateY(0px)';
        });
 
        // Smooth openen van het dropdown-menu
        setTimeout(function() {
            menu.style.opacity = 1;
            menu.style.transform = 'translateY(0px)';
        }, 10);
 
        // Bepaal de positie van het geopende dropdown-menu
        var menuPosition = menu.getBoundingClientRect().top;
 
        // Pas de positie van de knoppen aan op basis van de positie van het menu
        buttons.forEach(function(btn) {
            var btnPosition = btn.getBoundingClientRect().top;
            var offset = menu.clientHeight;
            if (btnPosition > menuPosition) {
                btn.style.transform = 'translateY(' + offset + 'px)'; // Schuif de knoppen onder het geopende dropdown-menu naar beneden
            }
        });
    }
}
 
function toggleHelp() {
    var helpMessage = document.getElementById("helpMessage");
    helpMessage.style.display = (helpMessage.style.display === "block") ? "none" : "block";
    var overlay = document.getElementById('overlay');
     // Sluit alle pop-ups voordat de nieuwe wordt geopend
     closeAllPopups();
     overlay.style.display = 'block';
}
 
function closeHelp() {
    var helpMessage = document.getElementById("helpMessage");
    helpMessage.style.display = "none";
    var overlay = document.getElementById('overlay');
    overlay.style.display = 'none';
}
 
function closeAllPopups() {
    var popups = document.querySelectorAll('.popup');
    var overlay = document.getElementById('overlay');
    popups.forEach(function(popup) {
        popup.style.display = 'none';
    });
    overlay.style.display = 'none';
}

var savedMessages = []; // Een array om berichten op te slaan

// Functie om een nieuw bericht toe te voegen
function saveText() {
    var inputText = document.getElementById('textInput').value;
    if (inputText.trim() !== '') {
        savedMessages.push(inputText); // Voeg nieuw bericht toe aan de array
        document.getElementById('textInput').value = ''; // Maak het invoerveld leeg
        alert("Bericht opgeslagen!");
        displayMessages(); // Toon berichten in alle relevante pop-ups
    } else {
        alert("Voer alstublieft wat tekst in.");
    }
}



// Functie om bericht te bewerken
function editMessage(index) {
    var editInput = document.getElementById('editTextInput');
    var updateButton = document.querySelector('#popupB button');
    editInput.style.display = 'block';
    updateButton.style.display = 'block';
    editInput.value = savedMessages[index]; // Zet de huidige tekst in het invoerveld
    updateButton.onclick = function() { updateText(index); }; // Update het specifieke bericht
}

// Functie om de bewerkte tekst te updaten
function updateText(index) {
    var editedText = document.getElementById('editTextInput').value;
    if (editedText.trim() !== '') {
        savedMessages[index] = editedText; // Update het bericht in de array
        displayMessages(); // Toon bijgewerkte berichten
        closePopup('popupB'); // Optioneel: Sluit popupB na het bijwerken
    } else {
        alert("Voer alstublieft wat tekst in om bij te werken.");
    }
}


// Hulpmiddel functies
function closeAllPopups() {
    var popups = document.querySelectorAll('.popup');
    var overlay = document.getElementById('overlay');
    popups.forEach(function(popup) {
        popup.style.display = 'none';
    });
    overlay.style.display = 'none';
}

function closeHelp() {
    var helpMessage = document.getElementById("helpMessage");
    helpMessage.style.display = "none";
    var overlay = document.getElementById('overlay');
    overlay.style.display = 'none';
}

function displayMessages() {
    ['popupA', 'popupB', 'popupC', 'popup2'].forEach(function(popupId) {
        var popup = document.getElementById(popupId);
        var list = popup.querySelector('ul'); // Zoek de lijst binnen de popup
        if (!list) {
            list = document.createElement('ul');
            popup.querySelector('.popup-content').appendChild(list);
        }
        list.innerHTML = ''; // Maak de lijst leeg voordat nieuwe items worden toegevoegd

        // Voeg berichten toe aan de lijst
        savedMessages.forEach(function(message, index) {
            var listItem = document.createElement('li');
            listItem.textContent = message;
            list.appendChild(listItem);

            if (popupId === 'popupB') {
                listItem.onclick = function() { editMessage(index); }; // Bewerken in popupB
            } else if (popupId === 'popupC') {
                listItem.onclick = function() { confirmDelete(index); }; // Verwijderen in popupC
            } else if (popupId === 'popup2') {
                // Voeg hier de logica toe voor de klikactie in popup2
                listItem.onclick = function() {
                    displayInPopup1(message); // Toon het bericht in popup1
                    alert("Bericht toegevoegd aan Huidige Planning."); // Alert om de actie te bevestigen
                };
            }
        });
    });
}



function confirmDelete(index) {
    var confirmAction = confirm("Weet je zeker dat je dit bericht wilt verwijderen?");
    if (confirmAction) {
        savedMessages.splice(index, 1); // Verwijder het bericht uit de array
        displayMessages(); // Toon bijgewerkte berichtenlijst in alle pop-ups
    } else {
        alert("Verwijderen geannuleerd.");
    }
}

// Functie om bericht te bewerken (bestaande code)
function editMessage(index) {
    var editInput = document.getElementById('editTextInput');
    var updateButton = document.querySelector('#popupB button');
    editInput.style.display = 'block';
    updateButton.style.display = 'block';
    editInput.value = savedMessages[index]; // Zet de huidige tekst in het invoerveld
    updateButton.onclick = function() { updateText(index); }; // Update het specifieke bericht
}

// Andere bestaande functies blijven hetzelfde

// Functie om de berichtenlijst te laden vanuit localStorage wanneer de pagina laadt
function loadMessages() {
    var storedMessages = localStorage.getItem('savedMessages');
    if (storedMessages) {
        savedMessages = JSON.parse(storedMessages); // Parse de JSON string terug naar een array
    } else {
        savedMessages = []; // Start met een lege array als er niets in localStorage staat
    }
    displayMessages(); // Toon de berichten
}

// Functie om de huidige staat van berichten op te slaan in localStorage
function saveMessagesToStorage() {
    localStorage.setItem('savedMessages', JSON.stringify(savedMessages)); // Sla de array op als een JSON string
}

// Update de saveText en updateText functies om ook op te slaan naar localStorage
function saveText() {
    var inputText = document.getElementById('textInput').value;
    if (inputText.trim() !== '') {
        savedMessages.push(inputText); // Voeg nieuw bericht toe aan de array
        document.getElementById('textInput').value = ''; // Maak het invoerveld leeg
        alert("Bericht opgeslagen!");
        saveMessagesToStorage(); // Sla de berichtenlijst op
        displayMessages(); // Toon berichten in alle relevante pop-ups
    } else {
        alert("Voer alstublieft wat tekst in.");
    }
}

function updateText(index) {
    var editedText = document.getElementById('editTextInput').value;
    if (editedText.trim() !== '') {
        savedMessages[index] = editedText; // Update het bericht in de array
        saveMessagesToStorage(); // Sla de berichtenlijst op
        displayMessages(); // Toon bijgewerkte berichten
        closePopup('popupB'); // Optioneel: Sluit popupB na het bijwerken
    } else {
        alert("Voer alstublieft wat tekst in om bij te werken.");
    }
}

// Voeg de confirmDelete functie aan om ook op te slaan naar localStorage na verwijdering
function confirmDelete(index) {
    var confirmAction = confirm("Weet je zeker dat je dit bericht wilt verwijderen?");
    if (confirmAction) {
        savedMessages.splice(index, 1); // Verwijder het bericht uit de array
        saveMessagesToStorage(); // Sla de berichtenlijst op
        displayMessages(); // Toon bijgewerkte berichtenlijst in alle pop-ups
    } else {
        alert("Verwijderen geannuleerd.");
    }
}

// Zorg ervoor dat berichten worden geladen wanneer de pagina laadt
window.onload = loadMessages;




