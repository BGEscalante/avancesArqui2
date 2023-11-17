const express = require('express');
const http = require('http');
const socketIO = require('socket.io');
const { Board, Led, Proximity } = require('johnny-five');

const app = express();
const server = http.createServer(app);
const io = socketIO(server);

app.use(express.static(__dirname + '/public'));

// Conexión a Johnny-Five
const board = new Board();

let led, led2 , proximity;
board.on('ready', () => {
  led = new Led(13);
  led2 = new Led(12);
   proximity = new Proximity({
    controller: 'HCSR04',
    pin: 7
  });

  io.on('connection', (socket) => {
    console.log('Cliente conectado');

    socket.on('encender_luz', () => {
      led.on();
      led2.on();
      io.emit('luz_estado', true);
    });

    socket.on('apagar_luz', () => {
      led.off();
      io.emit('luz_estado', false);
    });

    let medirDistanciaInterval;
    socket.on('medir_distancia', () => {
      medirDistanciaInterval = setInterval(() => {
        proximity.on('data', function () {
          io.emit('distancia', this.cm);
        });
      }, 500); // Cambia el intervalo según sea necesario
    });

    socket.on('detener_medicion', () => {
      clearInterval(medirDistanciaInterval);
      proximity.off();
    });
  });
});

const PORT = process.env.PORT || 3000;
server.listen(PORT, () => {
  console.log(`Servidor iniciado en el puerto ${PORT}`);
});
