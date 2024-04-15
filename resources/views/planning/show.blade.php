<!-- resources/views/planning/show.blade.php -->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="{{ asset('cssfiles/style.css') }}">
    <meta name="csrf-token" content="{{ csrf_token() }}">
    <title>Huidige Planning</title>
</head>
<body>
    <h1>Huidige Planning</h1>
    <p id="selectedMessage">Laden...</p>
    <script>
        document.addEventListener('DOMContentLoaded', function() {
            fetch('{{ route('planning') }}')
                .then(response => response.json())
                .then(data => {
                    document.getElementById('selectedMessage').textContent = data.planning ? data.planning.content : 'Geen planning beschikbaar.';
                })
                .catch(error => {
                    console.error('Error loading the planning:', error);
                    document.getElementById('selectedMessage').textContent = 'Fout bij het laden van de planning.';
                });
        });
    </script>
</body>
</html>
