<!DOCTYPE html>
<html lang="nl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Home</title>
    <link rel="stylesheet" href="{{ asset('cssfiles/style.css') }}">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.4/css/all.min.css">
</head>
<body>
    <button class="back-button"><a href="{{ route('welcome') }}"><i class="fas fa-arrow-left"></i> Terug naar homepage</a></button>
    <div class="container">
        <div class="title">Kirchner</div>
        <div class="menu" id="myPlanningMenu">
            <div class="dropdown">
                <button class="dropbtn" onclick="toggleMenu('myPlanning')">Mijn Planning <i class="fas fa-caret-down"></i></button>
                <div class="dropdown-content" id="myPlanning">
                    <a href="#" onclick="openPopup('popup1')">Huidige Planning</a>
                    <a href="#" onclick="openPopup('popup2')">Pas Mijn Planning Aan</a>
                    <a href="#" onclick="openPopup('popup3')">Verwijder Huidige Planning</a>
                </div>
            </div>
        </div>
        <div class="menu" id="oldMessagesMenu">
            <div class="dropdown">
                <button class="dropbtn" onclick="toggleMenu('oldMessages')">Oude Berichten <i class="fas fa-caret-down"></i></button>
                <div class="dropdown-content" id="oldMessages">
                    <a href="#" onclick="openPopup('popupA')">Oude Berichten Zien</a>
                    <a href="#" onclick="openPopup('popupB')">Pas Oude Berichten Aan</a>
                    <a href="#" onclick="openPopup('popupC')">Verwijder Oude Berichten</a>
                </div>
            </div>
        </div>
        <div class="menu" id="addMessagesMenu">
            <div class="dropdown">
                <button class="dropbtn" onclick="toggleMenu('addMessages')">Berichten Toevoegen <i class="fas fa-caret-down"></i></button>
                <div class="dropdown-content" id="addMessages">
                    <a href="#" onclick="openPopup('popupX')">Voeg Tekst Toe</a>
                    <a href="#" onclick="openPopup('popupY')">Voeg Animatie Toe</a>
                    <a href="#" onclick="openPopup('popupZ')">Voeg Datum/Tijd Toe</a>
                </div>
            </div>
        </div>
    </div>
    <div class="overlay" id="overlay" onclick="closeAllPopups()"></div> <!-- Overlay voor donkere achtergrond -->
    <div class="help-button" onclick="toggleHelp()">ℹ️</div> <!-- Button met emoji/icoon als vraagteken -->
    <div class="help-message" id="helpMessage"> <!-- Div voor het weergeven van het bericht -->
        <div class="help-content">
            <span class="close-button" onclick="closeHelp()">✖️</span> <!-- Button om het bericht te sluiten -->
            <h2>Handleiding</h2>
            <p>Hier komt de handleiding van hoe je de website moet gebruiken...</p>
        </div>
    </div>


    <!-- Pop-ups voor Mijn Planning -->
    <div class="popup" id="popup1">
        <span class="close-popup" onclick="closePopup('popup1')">✖️</span>
        <div class="popup-content">
            <h2>Huidige Planning</h2>
            <!-- Inhoud voor 'Huidige Planning' -->
        </div>
    </div>

    <div class="popup" id="popup2">
        <span class="close-popup" onclick="closePopup('popup2')">✖️</span>
        <div class="popup-content">
            <h2>Pas Mijn Planning Aan</h2>
            <!-- Inhoud voor 'Pas Mijn Planning Aan' -->
        </div>
    </div>

    <div class="popup" id="popup3">
        <span class="close-popup" onclick="closePopup('popup3')">✖️</span>
        <div class="popup-content">
            <h2>Verwijder Huidige Planning</h2>
            <p>De huidige planning is succesvol verwijderd.</p>
        </div>
    </div>

    <!-- Pop-ups voor Oude Berichten -->
    <div class="popup" id="popupA">
        <span class="close-popup" onclick="closePopup('popupA')">✖️</span>
        <div class="popup-content">
            <h2>Oude Berichten Zien</h2>
            <!-- Inhoud voor 'Oude Berichten Zien' -->
        </div>
    </div>

    <div class="popup" id="popupB">
        <span class="close-popup" onclick="closePopup('popupB')">✖️</span>
        <div class="popup-content">
            <h2>Pas Oude Berichten Aan</h2>
            <!-- Inhoud voor 'Pas Oude Berichten Aan' -->
        </div>
    </div>

    <div class="popup" id="popupC">
        <span class="close-popup" onclick="closePopup('popupC')">✖️</span>
        <div class="popup-content">
            <h2>Verwijder Oude Berichten</h2>
            <p>De oude berichten zijn succesvol verwijderd.</p>
        </div>
    </div>

    <!-- Pop-ups voor Berichten Toevoegen -->
    <div class="popup" id="popupX">
        <span class="close-popup" onclick="closePopup('popupX')">✖️</span>
        <div class="popup-content">
            <h2>Voeg Tekst Toe</h2>
            <input type="text" placeholder="Voer tekst in">
            <button>Verzenden</button>
        </div>
    </div>

    <div class="popup" id="popupY">
        <span class="close-popup" onclick="closePopup('popupY')">✖️</span>
        <div class="popup-content">
            <h2>Voeg Animatie Toe</h2>
            <!-- Inhoud voor 'Voeg Animatie Toe' -->
        </div>
    </div>

    <div class="popup" id="popupZ">
        <span class="close-popup" onclick="closePopup('popupZ')">✖️</span>
        <div class="popup-content">
            <h2>Voeg Datum/Tijd Toe</h2>
            <select id="datetimeType">
                <option value="datum">Datum</option>
                <option value="tijd">Tijd</option>
                <option value="datumtijd">Datum en Tijd</option>
            </select>
            <button onclick="submitDateTime()">Verzenden</button>
        </div>
    </div>

    <script src="{{ asset('js/script.js') }}"></script>
</body>
</html>
