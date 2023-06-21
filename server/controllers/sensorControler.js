const Sensor = require('../models/sensor.js');

module.exports = class SensorController{
    static async sensorAtivado(req,res){
        const {nome, distancia} = req.body;

        const sensor = new Sensor({
            nome,distancia
        })
        try{
            await sensor.save();
            res.status(201).json({message: "sensor salvo",sensor: sensor })
        } catch (error) {
            res.status(500).json({message:"deu ruim rapa"})
        }
    }
}