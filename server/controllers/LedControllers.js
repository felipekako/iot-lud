const cron = require('cron');
let ledstate = false;

const toggleLed =()=>{
    ledstate = !ledstate
    console.log('led state: ${ledstate}')
}

const job = new cron.CronJob('*/01* * * * *',toggleLed)

job.start();

module.export = class LedController{
    static async init(req,res){
        res.send({message: 'eeee'})
    }
    static async ledstate(req,res){
        res.json({state: ledstate})
    }
}