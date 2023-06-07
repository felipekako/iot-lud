const express = require('express')
const cors = require('cors')
const app = express();
const LedRouter = require('./routes/LedRoutes');
app.use(cors())

app.use('/led', LedRouter);

app.get('/',(req,res)=>{
    res.json({message: 'bem vindo a api '})
})
app.listen(3000,()=>{
    console.log('servidor rodando na porta 3000, para acessar use http://localhost:3000/')
})