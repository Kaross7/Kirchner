<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Laatste Planning</title>
</head>
<body>
    @if($planning)
        <p>{{ $planning->content }}</p>
    @else
        <p>Geen planningen beschikbaar.</p>
    @endif
</body>
</html>
