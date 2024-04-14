function openPopup(popupId) {
    var popup = document.getElementById(popupId);
    var overlay = document.getElementById('overlay');
     // Sluit alle pop-ups voordat de nieuwe wordt geopend
     closeAllPopups();
     closeHelp();
    popup.style.display = 'block';
    overlay.style.display = 'block';
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