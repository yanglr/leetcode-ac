<?php
// To-Do: 约瑟夫环问题
//LInk: http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=88
	$fd = fopen("stdin", "r");
	// $fd = STDIN;
	function judge($m, $n)
	{
	    $from = 0;
	    for($i = 2; $i < $n; $i++)
	      $from = ($from + $m)%($i);
	    if($from + 1 == 1) return 1;
	    else return 0;
	}

	while(fscanf($fd,"%d", $n)==1 && $n!=0)
	{
	    $m = 1;
	    while(!judge($m, $n))
	    {
	        ++$m;
	    }
	    echo $m."\n";
	}
