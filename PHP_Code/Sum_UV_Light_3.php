<?php
include "db_iconnect.php";

if (isset($_GET["device_id"])) {
    $device = $_GET["device_id"];
} else {
    // Handle the case when device_id is not provided
    echo "Error: device_id is missing.";
    exit;
}
$sunup = "2023-06-12 07:00:00";

//$query = "SELECT u.UV_max AS UV_Max, sec_to_time(unix_timestamp(NOW())-unix_timestamp('$sunup')) AS time_elapsed,

$query = "SELECT u.UV_max AS UV_Max, (unix_timestamp(NOW())-unix_timestamp('$sunup')) AS time_elapsed,
             SUM(UV_mesured) AS UV_measured_Total 
          FROM ixd_data d
          LEFT JOIN users u ON (d.user_id = u.id)
          WHERE user_id = ? 
          AND date_time >= '2023-06-13' 
          AND date_time <= '2023-06-14' 
          GROUP BY user_id";

// Prepare the statement
$stmt = $mysqli->prepare($query);
$stmt->bind_param("s", $device);
$stmt->execute();

// Get the result
$result = $stmt->get_result();

if ($result && $result->num_rows > 0) {
    // Fetch the result
    $data = $result->fetch_assoc();

    // Prepare the data to send back to ESP32
    $response = array(
        'UV_Max' => $data['UV_Max'],
        'UV_measured_Total' => $data['UV_measured_Total'],
        'time_elapsed' => $data['time_elapsed']
    );

    // Convert the data to JSON format
    $jsonData = json_encode($response);

    // Set the appropriate content type
    header('Content-Type: application/json');

    // Send the JSON data as the response
    echo $jsonData;
} else {
    // Handle the case when there is no data or error executing the query
    if ($result) {
        echo "No data found.";
    } else {
        // Handle query error
        echo "Error executing the query: " . $mysqli->error;
    }
}

$stmt->close();
?>
