<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Student Record Sorter</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            margin: 0;
            padding: 20px;
            background-color: #f4f4f4;
        }

        .container {
            max-width: 800px;
            margin: auto;
            background: white;
            padding: 20px;
            border-radius: 5px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }

        h1 {
            color: #333;
            text-align: center;
        }

        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
        }

        th,
        td {
            padding: 10px;
            border: 1px solid #ddd;
            text-align: left;
        }

        th {
            background-color: #f2f2f2;
        }
    </style>
</head>

<body>
    <div class="container">
        <h1>Student Records</h1>
        <?php
        // Database connection details
        $host = 'localhost';
        $dbname = 'student_records';
        $username = 'your_username';
        $password = 'your_password';
        try {
            $pdo = new PDO(
                "mysql:host=$host;dbname=$dbname"
                ,
                $username,
                $password
            );
            $pdo->setAttribute(
                PDO::ATTR_ERRMODE,
                PDO::ERRMODE_EXCEPTION
            );
            // Fetch student records
            $stmt = $pdo->query("SELECT * FROM students");
            $students = $stmt->fetchAll(PDO::FETCH_ASSOC);
            // Selection sort function
            function selectionSort(&$arr, $n)
            {
                for ($i = 0; $i < $n - 1; $i++) {
                    $min_idx = $i;
                    for ($j = $i + 1; $j < $n; $j++) {
                        if ($arr[$j]['gpa'] < $arr[$min_idx]['gpa']) {
                            $min_idx = $j;
                        }
                    }
                    if ($min_idx != $i) {
                        $temp = $arr[$i];
                        $arr[$i] = $arr[$min_idx];
                        $arr[$min_idx] = $temp;
                    }
                }
            }
            // Sort students by GPA
            selectionSort($students, count($students));
            // Display sorted student records
            echo "<table>";
            echo "<tr><th>ID</th><th>Name</th><th>GPA</th></tr>";
            foreach ($students as $student) {
                echo "<tr>";
                echo "<td>" . htmlspecialchars($student['id']) . "</td>";
                echo "<td>" . htmlspecialchars($student['name']) . "</td>";
                echo "<td>" . htmlspecialchars($student['gpa']) . "</td>";
                echo "</tr>";
            }
            echo "</table>";
        } catch (PDOException $e) {
            echo "Connection failed: " . $e->getMessage();
        }
        ?>
    </div>
</body>

</html>