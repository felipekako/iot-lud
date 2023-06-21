const mongoose = require('mongose')

const sensorSchema = new mongoose.Schema({
    nome: String,
    distancia: Number,
    horario: {type: Date,default: Date.now}
})

const Sensor = mongoose.model("sensor",sensorSchema)

module.exports = Sensor;