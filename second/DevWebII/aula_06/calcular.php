<?php
function Cal($numA, $numB, $choose) {
    switch($choose) {
        case '+':
            return $numA + $numB;
        case '-':
            return $numA - $numB;
        case '/':
            if($numB == 0) {
                return 0;
            }
            return $numA / $numB;
        case '*':
            return $numA * $numB;
    }
}

$numA = intval($_GET["numeroA"]);
$numB = intval($_GET["numeroB"]);
$choose = $_GET["operacao"];
$result = Cal($numA, $numB, $choose);

echo "O resultado da operação é: " . intval($result);
?>
