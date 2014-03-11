{
   "browser": {
      "clear_lso_data_enabled": true,
      "hung_plugin_detect_freq": 2000,
      "last_known_google_url": "http://www.google.com.hk/",
      "last_prompted_google_url": "http://www.google.com.hk/",
      "last_redirect_origin": "",
      "plugin_message_response_timeout": 30000
   },
   "gpu_blacklist": {
      "entries": [ {
         "blacklist": [ "webgl" ],
         "description": "ATI Radeon X1900 is not compatible with WebGL on the Mac.",
         "device_id": [ "0x7249" ],
         "id": 1,
         "os": {
            "type": "macosx"
         },
         "vendor_id": "0x1002",
         "webkit_bugs": [ 47028 ]
      }, {
         "blacklist": [ "accelerated_compositing" ],
         "cr_bugs": [ 59302 ],
         "description": "GL driver is software rendered. Accelerated compositing is disabled.",
         "gl_renderer": {
            "op": "contains",
            "value": "software"
         },
         "id": 3,
         "os": {
            "type": "linux"
         }
      }, {
         "blacklist": [ "webgl" ],
         "description": "The Intel Mobile 945 Express family of chipsets is not compatible with WebGL.",
         "device_id": [ "0x27AE" ],
         "id": 4,
         "os": 