const router = require("express").routes()
const SensorController = require('../controllers/sensorControler')
router.post('/ativado',SensorController.sensorAtivado)
module.exports = router;