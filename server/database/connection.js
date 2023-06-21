const mongoose = require("mongoose")

const usuario = process.env.DB_USER
const senha = process.env.DB_PASS

const connect = ()=>{
    mongoose.connection (`mongodb+srv://${usuario}:${senha}@iot-felipe.y8w6saa.mongodb.net/test?retryWrites=true&w=majority`)
    const connection = mongoose.connection;

    connection.on("error",()=>{
        console.log("conectar com o mongoDB")
    })

    connection.on("open",()=>{
        console.log("conectando com o mongoDB")
    })
}

connect()