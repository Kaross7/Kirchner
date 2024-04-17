 
<!DOCTYPE html>
<html lang="nl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Website</title>
    <link rel="stylesheet" href="{{ asset('cssfiles/homepage.css') }}">
    <script src="{{ asset('js/script.js') }}"></script>
</head>
<body>
    <div class="title-container">
        <div class="title">Kirchner</div>
        <div class="subtitle1">Jouw Lichtkrant, </div>
        <div class="subtitle2">Jouw Persoonlijke Bericht.</div>
        <a href="{{ route('page1') }}" class="button">Begin met bewerken &gt;</a>
    </div>
</body>
</html>