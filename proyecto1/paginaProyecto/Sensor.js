const { Board, Proximity } = require('johnny-five');

const board = new Board({
  port: 'COM8' // Reemplaza con el puerto de tu Arduino
});

  board.on('ready', () => {
  const proximity = new Proximity({
    controller: 'HCSR04',
    pin: 7
  });

  setInterval(() => {
    proximity.once('data', () => {
      console.log(`Distancia: ${proximity.cm} cm`);
    });
  }, 30000); // Intervalo de 30 segundos (30000 milisegundos)
});
