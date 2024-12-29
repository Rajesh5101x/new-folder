<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Display Input Value</title>
</head>
<body>
    <h2>Input Value</h2>
    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $name = $_POST['name'];
        echo "<p>You entered: $name</p>";
    } else {
        echo "<p>No data submitted.</p>";
    }
    ?>
</body>
</html>
