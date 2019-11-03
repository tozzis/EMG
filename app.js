var express = require('express');

var app = express();
var server = app.listen(80, () => {
    console.log("start app");
})

var io = require('socket.io')(server);

app.use(express.static('public'));

const SerialPort = require('serialport'); 
const Readline = SerialPort.parsers.Readline;
const port = new SerialPort('COM3');
const parser = port.pipe(new Readline({delimiter: '\r\n'}));
parser.on('data', (temp) => {
    io.sockets.emit('temp', {temp:temp});
});

io.on('connection', (socket) => {
    console.log("Someone connected.");
})