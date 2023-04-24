# memset初始化

几个特殊的值

0----直接置0

0x7f------memset对int能赋最大的值

0x3f3f3f3f = 1061109567

0xc0c0c0c0 = -1061109568

memset(arr,0x80,sizeof(arr)); //set int to -2139062144
memset(arr,0x7F,sizeof(arr)); //set double to 1.38242e+306
memset(arr,0xFE,sizeof(arr)); //set double to -5.31401e+303

