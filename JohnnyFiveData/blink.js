five = require("johhny-five")<
var board = new five.Board({port:"***/dev/ttyACMO depende de cual sea el port del aruino creo***",repl:false});


board.on("ready",function(){
	var led = new five.Led(13);
	led.blink(500);
	
});

board.on("error,function(){
	console.log();
});
