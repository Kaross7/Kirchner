<!DOCTYPE html>
<html lang="nl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Home</title>
    <link rel="stylesheet" href="{{ asset('cssfiles/style.css') }}">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.4/css/all.min.css">
    <meta name="csrf-token" content="{{ csrf_token() }}">
</head>
<body>
    <button class="back-button"><a href="{{ route('welcome') }}"><i class="fas fa-arrow-left"></i> Terug naar homepage</a></button>
    <div class="container">
        <div class="title">Kirchner</div>
        <div class="menu" id="myPlanningMenu">
            <div class="dropdown">
                <button class="dropbtn" onclick="toggleMenu('myPlanning')">Mijn Planning <i class="fas fa-caret-down"></i></button>
                <div class="dropdown-content" id="myPlanning">
                    <a href="#" onclick="openPopup('popup1')">Zelf bericht in planning zetten</a>
                    <a href="#" onclick="openPopup('popup2')">Kies oude bericht(en)</a>
                    <a href="#" onclick="openPopup('popup3')">Verwijder oude bericht(en)</a>
                </div>
            </div>
        </div>
    </div>
    <div class="overlay" id="overlay" onclick="closeAllPopups()"></div>
    <div class="help-button" onclick="toggleHelp()">ℹ️</div>
    <div class="help-message" id="helpMessage">
        <div class="help-content">
            <span class="close-button" onclick="closeHelp()">✖️</span>
            <h2>Handleiding</h2>
            <p>Je hebt 3 knoppen die je kan gebruiken als je op Mijn Planning klikt, de knoppen spreken voor zichzelf :)</p>
        </div>
    </div>

    <!-- Popup 1: Bericht Toevoegen -->
    <div id="popup1" class="popup">
        <div class="popup-content">
            <span class="close-button" onclick="closePopup('popup1')">✖️</span>
            <h2>Bericht Toevoegen</h2>
            @if(session('success'))
                <div class="alert alert-success">
                {{ session('success') }}
                </div>
            @endif

            <form id="planningForm" action="{{ route('plannings.store') }}" method="POST">
                @csrf
                <textarea name="content" placeholder="Typ je bericht hier..." required></textarea>
                <button type="submit">Verzend</button>
            </form>
        </div>
    </div>

    <!-- Popup 2: Oude Berichten -->
    <div id="popup2" class="popup">
    <div class="popup-content">
        <span class="close-button" onclick="closePopup('popup2')">✖️</span>
        <h2>Oude Berichten</h2>
        <ul>
            @foreach($plannings as $planning)
                <li>
                    {{ $planning->content }}
                    <button onclick="replicatePlanning({{ $planning->id }})">Opnieuw Publiceren</button>
                </li>
            @endforeach
        </ul>
    </div>
</div>

<!-- Popup 3: Berichten Verwijderen -->
<div id="popup3" class="popup">
    <div class="popup-content">
        <span class="close-button" onclick="closePopup('popup3')">✖️</span>
        <h2>Berichten Verwijderen</h2>
        <ul>
            @foreach($plannings as $planning)
                <li>{{ $planning->content }} <button onclick="deletePlanning({{ $planning->id }})">Verwijder</button></li>
            @endforeach
        </ul>
    </div>
</div>

    <script src="{{ asset('js/script.js') }}"></script>
</body>
</html>
