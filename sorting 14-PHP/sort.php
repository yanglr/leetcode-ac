<?php
if (PHP_SAPI == 'cli') {
	define('EOL', PHP_EOL);
	define('T', "\t");
} else {
	define('EOL', "<br/>");
	define('T', "&nbsp;");
}
error_reporting(E_ALL);

/*
Available algorithms:
 <= 0.010 (when size is 8000)
 - sort (native)

 <= 0.100 (when size is 8000)
 - countingSort
 - quickSort

 <= 0.200 (when size is 8000)
 - combSort
 - heapSort

 <= 1.000 (when size is 8000)
 - mergeSort

 <= 10.000 (when size is 8000)
 - shellSort

 <= 20.000 (when size is 8000)
 - selectionSort
 - insertSort
 - gnomeSort
 - combinedBubbleSort

 <= 30.000 (when size is 8000)
 - cocktailSort
 - bubbleSort
 - oddEvenSort
 - bubbleSortWithFlag
*/


// runTests(array('countingSort', 'heapSort', 'shellSort', 'insertSort', 'selectionSort', 'combSort', 'quickSort', 'mergeSort', 'gnomeSort', 'cocktailSort', 'oddEvenSort', 'bubbleSort', 'bubbleSortWithFlag', 'combinedBubbleSort'/*, 'stupidSort'*/), 8000, 2);
 // runTests(array('heapSort', 'countingSort'), 10000);

 if (in_array('--bigInt', $argv)) {
 	define('BIGINT', true);
 } else {
 	define('BIGINT', false);

 }

$sizes = array(1, 100, 200, 400, 600, 800, 1000, 5000, 10000, 15000, 20000, 25000, 30000);
if (isset($argv[2]) && $argv[2] == 'extra') {
	$sizes = array_merge($sizes, array(40000, 50000, 100000, 200000));
	if (isset($argv[3]) && $argv[3] == 'super') {
		$sizes = array_merge($sizes, array(300000, 500000, 1000000, 2000000));
	}
} else if (isset($argv[2]) && $argv[2] == 'micro') {
	$sizes = array(1, 100, 200, 400, 600, 800, 1000);
}
if (isset($argv[1])) {
	echo "Benchmarking ".$argv[1].EOL;
	batchTest(array($argv[1]), $sizes, 3);
} else {
	batchTest(array('quickSort', 'combSort', 'mergeSort', 'shellSort'), $sizes, 3);
}
// batchTest(array('insertSort', 'selectionSort'), $sizes, 3);

function countingSort(&$a) {
	$k = max($a);
	$c = array();
	$n = count($a);
	for ($i = 0; $i <= $k; $i++)
		$c[$i] = 0;
	for ($i = 0;$i < $n; $i++) {
		$c[$a[$i]]++;
	}
	$b = 0;
	for ($j = 0;$j <= $k; $j++) {
		for ($i = 0; $i < $c[$j]; $i++) {
			$a[$b] = $j;
			$b++;
		}
	}
}

function heapSort(&$a) {
	$n = count($a);
	heapMake($a);
	while ($n > 0) {
		list($a[0], $a[$n - 1]) = array($a[$n - 1], $a[0]);
		$n--;
		heapify($a, 0, $n);
	}
}

function heapMake(&$a) {
	$n = count($a);
	for ($i = ($n - 1); $i >= 0; $i--) {
		heapify($a, $i, $n);
	}
}

function heapify(&$a, $pos, $n) {
	while (2 * $pos + 1 < $n) {
		$t = 2 * $pos +1;
		if (2 * $pos + 2 < $n && $a[2 * $pos + 2] >= $a[$t]) {
			$t = 2 * $pos + 2;
		}
		if ($a[$pos] < $a[$t]) {
			list($a[$pos], $a[$t]) = array($a[$t], $a[$pos]);
			$pos = $t;
		}
		else break;
	}
}

function batchTest(array $functions, $sizes, $testSize = 1) {
	$times = array();
	$files = array();
	foreach ($functions as $f) {
		$files[$f] = fopen('result_'.$f.(BIGINT ? 'big' : null).'.txt', 'w');
		foreach ($sizes as $s)
			$times[$f][$s] = 0;
	}

	foreach ($sizes as $arraySize) {
		echo 'Start '.$arraySize;
		for ($i = 0; $i < $testSize; $i ++) {
			$a = fillArray($arraySize, BIGINT);
			$expected = $a;
			sort($expected);
			foreach ($functions as $function) {
				echo '.';
				$array = $a;
				$time = testAlgorithm($function, $array);
				$times[$function][$arraySize] += $time;
				if ($array != $expected) {
					echo $function." is wrong".EOL;
					if ($batchSize <= 10) {
						echo "expected: ";
						printArray($expected);
						echo "actual: ";
						printArray($array);
					}
				}
			}
		}

		foreach ($files as $function => $res) {
			fwrite($res, $arraySize."\t".sprintf("%f", $times[$function][$arraySize] / $testSize).PHP_EOL);
		}
		echo 'done'.EOL;
	}

	foreach ($files as $res) {
		fclose($res);
	}

	// foreach ($times as $f => $times) {
	// 	echo $f.EOL;
	// 	echo "arraySize".T."time".EOL;
	// 	if (file_exists($f.'.txt')) unlink($f.'.txt');
	// 	foreach ($times as $arraySize => $time) {
	// 		echo $arraySize.T.sprintf("%f", $time / $testSize).EOL;
	// 		file_put_contents($f.'.txt', $arraySize.T.sprintf("%f", $time / $testSize).PHP_EOL, FILE_APPEND);
	// 	}
	// }
}

// runTests(array('shellSort'), 10000);

function shellSort(&$a) {
	$n = count($a);
	$d = floor($n / 2);
	while ($d > 0) {
		for ($i = 0; $i < ($n - $d); $i++) {
			$j = $i;
			while ($j >= 0 && $a[$j] > $a[$j + $d]) {
				list($a[$j], $a[$j + $d]) = array($a[$j + $d], $a[$j]);
				$j--;
			}
		}
		$d = floor($d / 2);
	}
}

function insertSort(&$a) {
	$n = count($a);
	for ($i = 0; $i < ($n - 1); $i++) {
		$key = $i + 1;
		$tmp = $a[$key];
		for ($j = ($i + 1); $j > 0; $j--) {
			if ($tmp < $a[$j - 1]) {
				$a[$j] = $a[$j - 1];
				$key = $j - 1;
			}
		}
		$a[$key] = $tmp;
	}
}

function selectionSort(&$a) {
	$n = count($a);
	for ($i = 0; $i < ($n - 1); $i++) {
		$key = $i;
		for ($j = ($i + 1); $j < $n; $j++) {
			if ($a[$j] < $a[$key]) $key = $j;
		}
		if ($key != $i) {
			list($a[$key], $a[$i]) = array($a[$i], $a[$key]);
		}
	}
}

function mergeSort(&$a, $first = 0, $last = null) {
	if (is_null($last)) $last = count($a) - 1;
	$function = __FUNCTION__;
	if ($first < $last) {
		$function($a, $first, floor(($first + $last) / 2));
		$function($a, floor(($first + $last) / 2) + 1, $last);

		$tmp = array();

		$middle = floor(($first + $last) / 2);
		$start = $first;
		$final = $middle + 1;
		for ($i = $first; $i <= $last; $i++) {
			if (($start <= $middle) && (($final > $last) || ($a[$start] < $a[$final]))) {
				$tmp[$i] = $a[$start];
				$start++;
			} else {
				$tmp[$i] = $a[$final];
				$final++;
			}
		}

		for ($i = $first; $i <= $last; $i++) {
			$a[$i] = $tmp[$i];
		}
	}
}

function quickSort(&$a, $l = 0, $r = 0) {
	if($r == 0) $r = count($a)-1;
	$i = $l;
	$j = $r;
	$x = $a[($l + $r) / 2];
	do {
		while ($a[$i] < $x) $i++;
		while ($a[$j] > $x) $j--;
		if ($i <= $j) {
			if ($a[$i] > $a[$j])
				list($a[$i], $a[$j]) = array($a[$j], $a[$i]);
			$i++;
			$j--;
		}
	} while ($i <= $j);
	$function = __FUNCTION__;
	if ($i < $r) $function($a, $i, $r);
	if ($j > $l) $function($a, $l, $j);
}

function gnomeSort(&$a) {
	$n = count($a);
	$i = 1;
	$j = 2;
	while ($i < $n) {
		if ($a[$i - 1] < $a[$i]) {
			$i = $j;
			$j++;
		} else {
			list($a[$i], $a[$i - 1]) = array($a[$i - 1], $a[$i]);
			$i--;
			if ($i == 0) {
				$i = $j;
				$j++;
			}
		}
	}
}

function oddEvenSort(&$a) {
	$n = count($a);
	$sorted = false;
	while (!$sorted) {
		$sorted = true;
		for ($i = 1; $i < ($n - 1); $i += 2) {
			if ($a[$i] > $a[$i + 1]) {
				//echo "Swap ";
				list($a[$i], $a[$i + 1]) = array($a[$i + 1], $a[$i]);
				//printArray($a, array($i, $i + 1), 'blue');
				if ($sorted) $sorted = false;
			}
		}

		for ($i = 0; $i < ($n - 1); $i += 2) {
			if ($a[$i] > $a[$i + 1]) {
				//echo "Swap ";
				list($a[$i], $a[$i + 1]) = array($a[$i + 1], $a[$i]);
				//printArray($a, array($i, $i + 1), 'blue');
				if ($sorted) $sorted = false;
			}
		}
	}
}

function combSort(&$a) {
	$gap = $n = count($a);
	$swapped = true;
	while ($gap > 1 || $swapped) {
		if ($gap > 1) $gap = floor($gap / 1.24733);
		$i = 0;
		$swapped = false;
		while ($i + $gap < $n) {
			if ($a[$i] > $a[$i + $gap]) {
				list($a[$i], $a[$i + $gap]) = array($a[$i + $gap], $a[$i]);
				if (!$swapped) $swapped = true;
			}
			$i++;
		}
	}
}

function fakeSort(&$a) {}


function cocktailSort(&$a) {
	$n = count($a);
	$left = 0;
	$right = $n - 1;
	do {
		//echo "# Left: ".$left." Right: ".$right.EOL;
		for ($i = $left; $i < $right; $i++) {
			//echo "Comparation: ";
			//printArray($a, array($i, $i + 1));
			if ($a[$i] > $a[$i + 1]) {
				//echo "Swap ";
				list($a[$i], $a[$i + 1]) = array($a[$i + 1], $a[$i]);
				//printArray($a, array($i, $i + 1), 'blue');
			}
		}
		$right -= 1;
		for ($i = $right; $i > $left; $i--) {
			//echo "Comparation: ";
			//printArray($a, array($i, $i - 1));
			if ($a[$i] < $a[$i - 1]) {
				//echo "Swap ";
				list($a[$i], $a[$i - 1]) = array($a[$i - 1], $a[$i]);
				//printArray($a, array($i, $i - 1), 'blue');
			}
		}
		$left += 1;
	} while ($left <= $right);
}

function runTests($functions, $arraySize = 100, $batchSize = 1) {
	$times = array('sort' => 0);
	foreach ($functions as $f) $times[$f] = 0;

	for ($i = 0; $i < $batchSize; $i ++) {
		echo "Iteration #".$i.EOL;
		$a = fillArray($arraySize);
		$expected = $a;
		// sort($expected);
		$times['sort'] += testAlgorithm('sort', $expected);
		foreach ($functions as $function) {
			$array = $a;
			$time = testAlgorithm($function, $array);
			echo "+".$time.EOL;
			$times[$function] += $time;
			if ($array != $expected) {
				echo $function." is wrong".EOL;
				if ($batchSize <= 10) {
					echo "expected: ";
					printArray($expected);
					echo "actual: ";
					printArray($array);
				}
			}
		}
	}

	asort($times);
	foreach ($times as $function => $time) {
		echo "time ".$function."(x".$batchSize.")".T.round($times[$function] / $batchSize, 3).T.round($times[$function], 3).EOL;
	}

	echo "Total time".T.T.round(array_sum($times), 3).EOL;
	//echo "Average time: ".round($times / $batchSize, 3).EOL;
}
function testAlgorithm($function, &$a) {
	$st = microtime(true);
	//call_user_func($function, $a);
	$function($a);
	$en = microtime(true) - $st;
	return $en;
}
function fillArray($s, $isBigInt = false) {
	$limit = $s;
	if ($isBigInt) {
		$limit = PHP_INT_MAX;
	}
	$a = array();
	for ($i=0; $i<$s;$i++) {
		$a[] = rand(1, $limit);
	}
	return $a;
}
function printArray($a, $keys = null, $color = 'red') {
	if (!is_null($keys)) foreach ($keys as $k) $a[$k] = "<span style='color: ".$color."'>".$a[$k]."</span>";
	echo '[';
	echo implode(', ', $a);
	echo ']'.EOL;
}

function bubbleSort(&$a) {
	$n = count($a);
	// bubble sorting
	for ($j = 0; $j < ($n - 1); $j++) {
		//echo "Iteration #".$j.EOL;
		for ($i = 0; $i < ($n - $j - 1); $i++) {
			//echo T.'#'.$i.T.'v'.$a[$i].EOL;
			//echo "Comparation: ";
			//printArray($a, array($i, $i + 1));
			if ($a[$i] > $a[$i + 1]) {
				//echo "Swap: ";
				list($a[$i], $a[$i + 1]) = array($a[$i + 1], $a[$i]);
				//printArray($a, array($i, $i + 1), 'blue');
			}
		}
	}
}

function bubbleSortWithFlag(&$a) {
	$n = count($a);
	// bubble sorting
	for ($j = 0; $j < ($n - 1); $j++) {
		//echo "Iteration #".$j.EOL;
		$flag = false;
		for ($i = 0; $i < ($n - $j - 1); $i++) {
			//echo T.'#'.$i.T.'v'.$a[$i].EOL;
			//echo "Comparation: ";
			//printArray($a, array($i, $i + 1));
			if ($a[$i] > $a[$i + 1]) {
				//echo "Swap: ";
				list($a[$i], $a[$i + 1]) = array($a[$i + 1], $a[$i]);
				//printArray($a, array($i, $i + 1), 'blue');
				if (!$flag) $flag = true;
			}
		}
		if (!$flag) break;
	}
}

function combinedBubbleSort(&$a) {
	$n = count($a);
	// bubble sorting
	for ($j = 0; $j < ($n - 1); $j++) {
		//echo "Iteration #".$j.EOL;
		$flag = false;
		$min = $j;
		for ($i = $j; $i < ($n - $j - 1); $i++) {
			//echo T.'#'.$i.T.'v'.$a[$i].EOL;
			//echo "Comparation: ";
			//printArray($a, array($i, $i + 1));
			if ($a[$i] > $a[$i + 1]) {
				//echo "Swap: ";
				list($a[$i], $a[$i + 1]) = array($a[$i + 1], $a[$i]);
				//printArray($a, array($i, $i + 1), 'blue');
				if (!$flag) $flag = true;
			}
			if ($a[$i] < $a[$min]) $min = $i;
		}
		if (!$flag) break;
		if ($min != $j) {
			//echo "Swap: ";
			list($a[$min], $a[$j]) = array($a[$j], $a[$min]);
			//printArray($a, array($min, $j), 'yellow');
		}
	}
}

function stupidSort(&$a) {
	$n = count($a);
	for ($i = 1; $i < $n; $i ++) {
	//echo "Iteration #".$i.EOL;
		if ($a[$i] < $a[$i - 1]) {
			//echo "Swap :";
			list($a[$i], $a[$i - 1]) = array($a[$i - 1], $a[$i]);
			//printArray($a, array($i, $i - 1));
			$i = 0;
			continue;
		}
	}
}
