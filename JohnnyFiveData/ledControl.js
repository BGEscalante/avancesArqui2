five = require("johhny-five");
var board = new five.Board({port:"***/dev/ttyACMO***",repl:false});


board.on("ready",function(){
	var led = new five.Led(13);
	led.off;
	this.repl.inject({
		l1: led
	});
	
});

board.on("error,function(){
	console.log();
});
