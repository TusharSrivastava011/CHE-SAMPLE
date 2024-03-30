<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Carbon Footprint Calculator</title>
    <style>
        /* CSS styles for layout and design */
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f4f4f4;
        }
        header {
            background-color: #333;
            color: #fff;
            padding: 10px 0;
            text-align: center;
        }
        nav ul {
            list-style-type: none;
            margin: 0;
            padding: 0;
        }
        nav ul li {
            display: inline;
            margin-right: 20px;
        }
        nav ul li a {
            color: #fff;
            text-decoration: none;
        }
        main {
            padding: 20px;
        }
        form {
            background-color: #fff;
            padding: 20px;
            border-radius: 5px;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
        }
        label {
            display: block;
            margin-bottom: 10px;
        }
        input[type="text"],
        select {
            width: 100%;
            padding: 10px;
            margin-bottom: 20px;
            border: 1px solid #ccc;
            border-radius: 5px;
            box-sizing: border-box;
        }
        input[type="submit"] {
            background-color: #333;
            color: #fff;
            padding: 10px 20px;
            border: none;
            border-radius: 5px;
            cursor: pointer;
        }
        footer {
            background-color: #333;
            color: #fff;
            text-align: center;
            padding: 10px 0;
            position: fixed;
            bottom: 0;
            width: 100%;
        }
    </style>
</head>
<body>
    <header>
        <h1>Carbon Footprint Calculator</h1>
        <nav>
            <ul>
                <li><a href="#">Home</a></li>
                <li><a href="#">Calculator</a></li>
                <li><a href="#">About</a></li>
                <li><a href="#">Contact</a></li>
            </ul>
        </nav>
    </header>
    <main>
        <section>
            <h2>Calculate Your Carbon Footprint</h2>
            <form action="#" method="post">
                <label for="commute">Daily Commute Distance (miles)</label>
                <input type="text" id="commute" name="commute" required>

                <label for="vehicle">Vehicle Type</label>
                <select id="vehicle" name="vehicle">
                    <option value="car">Car</option>
                    <option value="bike">Bike</option>
                    <option value="bus">Bus</option>
                    <option value="train">Train</option>
                    <option value="other">Other</option>
                </select>

                <label for="mileage">Vehicle Mileage (mpg)</label>
                <input type="text" id="mileage" name="mileage" required>

                <input type="submit" value="Calculate">
            </form>
        </section>
        <section id="result" style="display: none;">
            <h2>Carbon Footprint Report</h2>
            <p>Your carbon footprint is <span id="carbon-footprint"></span> kg CO2 per day.</p>
            <h3>Suggestions for Reducing Emissions</h3>
            <ul id="suggestions">
                <li>Carpooling with colleagues or friends.</li>
                <li>Using public transportation.</li>
                <li>Switching to electric vehicles.</li>
            </ul>
        </section>
    </main>
    <footer>
        <p>&copy; 2024 Carbon Footprint Calculator</p>
    </footer>
    <script>
        // JavaScript for handling form submission and calculating carbon footprint
        document.querySelector('form').addEventListener('submit', function(event) {
            event.preventDefault();

            // Retrieve form values
            let commuteDistance = parseFloat(document.getElementById('commute').value);
            let vehicleType = document.getElementById('vehicle').value;
            let mileage = parseFloat(document.getElementById('mileage').value);

            // Calculate carbon footprint
            let carbonFootprint = calculateCarbonFootprint(commuteDistance, vehicleType, mileage);

            // Display results
            document.getElementById('carbon-footprint').textContent = carbonFootprint.toFixed(2);
            document.getElementById('result').style.display = 'block';
        });

        function calculateCarbonFootprint(distance, vehicle, mpg) {
            let emissionFactor = getEmissionFactor(vehicle);
            return (distance / mpg) * emissionFactor;
        }

        function getEmissionFactor(vehicle) {
            // Emission factors in kg CO2 per mile
            const emissionFactors = {
                car: 0.404,
                bike: 0,
                bus: 0.22,
                train: 0.21,
                other: 0.2 // Assuming for any other mode of transport
            };
            return emissionFactors[vehicle];
        }
    </script>
</body>
</html>
