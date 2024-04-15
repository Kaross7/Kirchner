function openPopup(popupId) {
    closeAllPopups(); // Zorgt voor het sluiten van alle pop-ups en verwijderen van de overlay
    var popup = document.getElementById(popupId);
    popup.style.display = 'block';
    document.getElementById('overlay').style.display = 'block';
}

function closePopup(popupId) {
    var popup = document.getElementById(popupId);
    var overlay = document.getElementById('overlay');
    popup.style.display = 'none';
    overlay.style.display = 'none';
}

function toggleMenu(menuId) {
    const menu = document.getElementById(menuId);
    const menus = document.querySelectorAll('.dropdown-content');
    const buttons = document.querySelectorAll('.dropbtn');

    menus.forEach(item => {
        item.style.display = (item.id === menuId && item.style.display !== "block") ? "block" : "none";
    });

    // Reset de positie van de knoppen
    buttons.forEach(btn => {
        btn.style.transform = 'translateY(0px)';
    });

    if (menu.style.display === "block") {
        setTimeout(() => {
            menu.style.opacity = 1;
            menu.style.transform = 'translateY(0px)';
        }, 10);
    }
}

function deletePlanning(id) {
    if (confirm('Weet je zeker dat je dit wilt verwijderen?')) {
        fetch(`/plannings/${id}`, {
            method: 'DELETE',
            headers: {
                'X-CSRF-TOKEN': document.querySelector('meta[name="csrf-token"]').getAttribute('content'),
                'Content-Type': 'application/json'
            }
        }).then(response => response.json())
          .then(data => {
              if (data.success) {
                  alert('Planning verwijderd');
                  window.location.reload(); // Herlaadt de pagina om de lijst te vernieuwen
              }
          })
          .catch(error => console.error('Error:', error));
    }
}

document.addEventListener('DOMContentLoaded', function () {
    const form = document.getElementById('planningForm');
    form.addEventListener('submit', function (e) {
        e.preventDefault();
        const formData = new FormData(form);
        fetch(form.action, {
            method: 'POST',
            body: formData,
            headers: {
                'X-CSRF-TOKEN': document.querySelector('meta[name="csrf-token"]').getAttribute('content')
            }
        })
        .then(response => response.json())
        .then(data => {
            alert(data.message);  // Toon een JavaScript alert met het bericht van de server
            if (data.success) {
                window.location.reload(); // Optioneel: herlaad de pagina als de operatie succesvol was
            }
        })
        .catch(error => console.error('Error:', error));
    });
});


function toggleHelp() {
    const helpMessage = document.getElementById("helpMessage");
    const overlay = document.getElementById('overlay');
    if (helpMessage.style.display === "block") {
        helpMessage.style.display = "none";
        overlay.style.display = 'none';
    } else {
        closeAllPopups();
        helpMessage.style.display = "block";
        overlay.style.display = 'block';
    }
}

function closeHelp() {
    var helpMessage = document.getElementById("helpMessage");
    helpMessage.style.display = "none";
    var overlay = document.getElementById('overlay');
    overlay.style.display = 'none';
}

function closeAllPopups() {
    var popups = document.querySelectorAll('.popup');
    popups.forEach(function(popup) {
        popup.style.display = 'none';
    });
    document.getElementById('overlay').style.display = 'none';
    closeHelp(); // Zorgt ervoor dat help ook gesloten wordt als het open is
}

function replicatePlanning(id) {
    fetch(`/plannings/replicate/${id}`, {
        method: 'POST',
        headers: {
            'X-CSRF-TOKEN': document.querySelector('meta[name="csrf-token"]').getAttribute('content'),
            'Content-Type': 'application/json'
        }
    }).then(response => response.json())
      .then(data => {
          if (data.success) {
              alert('Planning opnieuw gepubliceerd');
              window.location.reload(); // Herlaadt de pagina om de lijst te vernieuwen
          }
      })
      .catch(error => console.error('Error:', error));
}


