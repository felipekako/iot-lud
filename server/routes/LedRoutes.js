const router = require("express").Router();
const LedController = require('../controllers/LedControllers');

router.get('/',LedController.init)
router.get('/state-led',LedController.ledstate)

module.export = router 