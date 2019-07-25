webpackJsonp([0],{

/***/ 111:
/***/ (function(module, exports) {

function webpackEmptyAsyncContext(req) {
	// Here Promise.resolve().then() is used instead of new Promise() to prevent
	// uncatched exception popping up in devtools
	return Promise.resolve().then(function() {
		throw new Error("Cannot find module '" + req + "'.");
	});
}
webpackEmptyAsyncContext.keys = function() { return []; };
webpackEmptyAsyncContext.resolve = webpackEmptyAsyncContext;
module.exports = webpackEmptyAsyncContext;
webpackEmptyAsyncContext.id = 111;

/***/ }),

/***/ 152:
/***/ (function(module, exports) {

function webpackEmptyAsyncContext(req) {
	// Here Promise.resolve().then() is used instead of new Promise() to prevent
	// uncatched exception popping up in devtools
	return Promise.resolve().then(function() {
		throw new Error("Cannot find module '" + req + "'.");
	});
}
webpackEmptyAsyncContext.keys = function() { return []; };
webpackEmptyAsyncContext.resolve = webpackEmptyAsyncContext;
module.exports = webpackEmptyAsyncContext;
webpackEmptyAsyncContext.id = 152;

/***/ }),

/***/ 196:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return HomePage; });
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_ionic_angular__ = __webpack_require__(30);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2__ionic_native_camera__ = __webpack_require__(195);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_3__providers_drawing_drawing__ = __webpack_require__(42);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_4__colors_popover_colors_popover__ = __webpack_require__(197);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_5__width_popover_width_popover__ = __webpack_require__(199);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_6__brush_type_popover_brush_type_popover__ = __webpack_require__(200);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_7__angular_http__ = __webpack_require__(201);
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};








var HomePage = (function () {
    function HomePage(popoverCtrl, actionSheetCtrl, platform, camera, drawing, http, loadingCtrl, alertCtrl) {
        this.popoverCtrl = popoverCtrl;
        this.actionSheetCtrl = actionSheetCtrl;
        this.platform = platform;
        this.camera = camera;
        this.drawing = drawing;
        this.http = http;
        this.loadingCtrl = loadingCtrl;
        this.alertCtrl = alertCtrl;
        this.drawingEnabled = true;
        this.text = 'Use Artificial Intellgence to create Photorealistic Paintings on your Phone!';
        this.url = 'https://loganoneal.com';
        this.host = 'http://localhost:80/';
    }
    //Alert Functions
    HomePage.prototype.reset = function () {
        var _this = this;
        var alert = this.alertCtrl.create({
            title: 'Confirm New',
            message: 'Are you sure you want to start a new painting?',
            buttons: [
                {
                    text: 'Yes',
                    role: 'yes',
                    handler: function () {
                        _this.drawing.canvas.clear();
                        _this.drawingEnabled = true;
                    }
                },
                {
                    text: 'Cancel',
                    role: 'cancel',
                    handler: function () {
                        console.log('Cancel clicked');
                        _this.drawingEnabled = true;
                    }
                }
            ],
            cssClass: "alertCss",
        });
        alert.present();
        console.log('reset');
    };
    HomePage.prototype.presentLoadingCustom = function () {
        var loading = this.loadingCtrl.create({
            spinner: 'hide',
            content: "<img src=\"assets/imgs/loading.gif\"/> Painting Your Masterpiece...",
            duration: 5000
        });
        loading.onDidDismiss(function () {
            console.log('Dismissed loading');
        });
        loading.present();
    };
    /**
     * Make sure you are calling create method inside of "ionViewDidLoad"
     */
    HomePage.prototype.ionViewDidLoad = function () {
        // we are here taking full screen for drawing, change this logic if you need something else
        var width = window.screen.width;
        var height = window.screen.height;
        this.drawing.create(width, height);
    };
    /**
     * In this method you can do something with your drawing
     */
    HomePage.prototype.upload = function () {
        var _this = this;
        // drawing variable is base64 image
        var drawing = this.drawing.getAsImage();
        this.presentLoadingCustom();
        /*
        var headers = new Headers();
          headers.append('Access-Control-Allow-Origin' , 'http://localhost:80/upload');
          headers.append('Access-Control-Allow-Methods', 'POST, GET, OPTIONS, PUT');
          headers.append('Accept','application/json');
          headers.append('content-type','application/json');
          let options = new RequestOptions({ headers:headers,withCredentials: false});*/
        var postData = drawing;
        this.http.post(this.host + "upload", postData)
            .subscribe(function (data) {
            console.log(data['_body']);
            var dataB = data.json();
            console.log("Location: " + " " + dataB['location'] + "\n");
            var imageSource = dataB['location'];
            _this.drawing.setCanvas(_this.host + imageSource);
        }, function (error) {
            console.log(error);
        });
    };
    /**
     * Switch back to drawing
     */
    HomePage.prototype.ok = function () {
        this.drawingEnabled = true;
        this.drawing.enableDrawing();
    };
    /**
     * Displays list of colors
     * @param event
     */
    HomePage.prototype.openColorsPopover = function (event) {
        var popover = this.popoverCtrl.create(__WEBPACK_IMPORTED_MODULE_4__colors_popover_colors_popover__["a" /* ColorsPopoverPage */]);
        popover.present({
            ev: event
        });
    };
    /**
     * Displays list of brush widths
     * @param event
     */
    HomePage.prototype.openWidthsPopover = function (event) {
        var popover = this.popoverCtrl.create(__WEBPACK_IMPORTED_MODULE_5__width_popover_width_popover__["a" /* WidthPopoverPage */]);
        popover.present({
            ev: event
        });
    };
    /**
     * Displays list of brush types
     * @param event
     */
    HomePage.prototype.openTypesPopover = function (event) {
        var popover = this.popoverCtrl.create(__WEBPACK_IMPORTED_MODULE_6__brush_type_popover_brush_type_popover__["a" /* BrushTypePopoverPage */]);
        popover.present({
            ev: event
        });
    };
    /**
     * Adds text
     */
    HomePage.prototype.addText = function () {
        var _this = this;
        var alert = this.alertCtrl.create({
            title: 'Add text',
            inputs: [
                {
                    name: 'text',
                    placeholder: 'Your text here'
                }
            ],
            buttons: [
                {
                    text: 'Cancel',
                    role: 'cancel',
                    handler: function () { }
                },
                {
                    text: 'OK',
                    handler: function (data) {
                        if (data.text === "")
                            return false;
                        // when adding text we need to disable drawing so that is possible
                        // to manage text on screen
                        _this.drawingEnabled = true;
                        _this.drawing.addText(data.text);
                    }
                }
            ]
        });
        alert.present();
    };
    /**
     * Adds image to canvas
     */
    HomePage.prototype.addImage = function () {
        var _this = this;
        var actionSheet = this.actionSheetCtrl.create({
            title: 'Add photo',
            buttons: [
                {
                    text: 'Take picture',
                    icon: 'camera',
                    handler: function () {
                        _this.takePicture(true)
                            .then(function (image) {
                            _this.drawingEnabled = true;
                            _this.drawing.addImage(image);
                        })
                            .catch(function () { });
                    }
                }, {
                    text: 'Select from gallery',
                    icon: 'image',
                    handler: function () {
                        _this.takePicture(false)
                            .then(function (image) {
                            _this.drawingEnabled = true;
                            _this.drawing.addImage(image);
                        })
                            .catch(function () { });
                    }
                }, {
                    text: 'Cancel',
                    icon: 'close',
                    handler: function () { }
                }
            ]
        });
        actionSheet.present();
    };
    /**
     * Adds background to canvas
     */
    HomePage.prototype.addBackground = function () {
        var _this = this;
        var actionSheet = this.actionSheetCtrl.create({
            title: 'Add background',
            buttons: [
                {
                    text: 'Take picture',
                    icon: 'camera',
                    handler: function () {
                        _this.takePicture(true)
                            .then(function (image) {
                            _this.drawing.addBackgroundImage(image);
                        }).catch(function () { });
                    }
                }, {
                    text: 'Select from gallery',
                    icon: 'image',
                    handler: function () {
                        _this.takePicture(false)
                            .then(function (image) {
                            _this.drawing.addBackgroundImage(image);
                        })
                            .catch(function () { });
                    }
                }, {
                    text: 'Cancel',
                    icon: 'close',
                    handler: function () { }
                }
            ]
        });
        actionSheet.present();
    };
    /**
     * Undo last change
     */
    HomePage.prototype.undo = function () {
        this.drawing.undo();
    };
    /**
     * Takes image from camera or photo gallery
     * @param from_camera
     */
    HomePage.prototype.takePicture = function (from_camera) {
        var _this = this;
        return new Promise(function (resolve, reject) {
            // define camera options
            var options = {
                quality: 50,
                allowEdit: true,
                saveToPhotoAlbum: false,
                cameraDirection: 0,
                correctOrientation: true,
                targetWidth: 1200,
                targetHeight: 800,
                sourceType: from_camera ? _this.camera.PictureSourceType.CAMERA : _this.camera.PictureSourceType.PHOTOLIBRARY,
                destinationType: _this.camera.DestinationType.DATA_URL,
                encodingType: _this.camera.EncodingType.JPEG
            };
            _this.camera.getPicture(options).then(function (image) { return resolve('data:image/jpeg;base64,' + image); }, function () { return reject(); });
        });
    };
    __decorate([
        Object(__WEBPACK_IMPORTED_MODULE_0__angular_core__["_8" /* ViewChild */])(__WEBPACK_IMPORTED_MODULE_1_ionic_angular__["c" /* Content */]),
        __metadata("design:type", __WEBPACK_IMPORTED_MODULE_1_ionic_angular__["c" /* Content */])
    ], HomePage.prototype, "content", void 0);
    HomePage = __decorate([
        Object(__WEBPACK_IMPORTED_MODULE_0__angular_core__["m" /* Component */])({
            selector: 'page-home',template:/*ion-inline-start:"/home/node-5/production/painting/frontend/src/pages/home/home.html"*/'<ion-content>\n        <!-- This is container on which we will be drawing things -->\n        <canvas id="drawing-container"></canvas>\n        <button ion-button  id="btn-l1" icon-only (click)="openColorsPopover($event)">\n            Current Material: {{this.drawing.brushTitle}}\n        </button>\n        <button ion-button id="btn-l2" (click)="upload()">\n            Upload\n        </button>\n        <button ion-button round id="btn-r1" ion-button (click)="openColorsPopover($event)">\n            <ion-icon color="secondary" name="color-palette"></ion-icon>\n        </button>\n        <button ion-button  round id="btn-r2" (click)="openWidthsPopover($event)" icon-only>\n            <ion-icon color="secondary" name="options"></ion-icon>\n        </button>\n        <button ion-button  round id="btn-r3" (click)="undo()" icon-only>\n            <ion-icon color="secondary" name="undo"></ion-icon>\n        </button>\n        <button ion-button round id="btn-r4" (click)="reset()" icon-only>\n                <ion-icon color="secondary" name="add"></ion-icon>\n        </button>\n</ion-content>\n'/*ion-inline-end:"/home/node-5/production/painting/frontend/src/pages/home/home.html"*/
        }),
        __metadata("design:paramtypes", [__WEBPACK_IMPORTED_MODULE_1_ionic_angular__["i" /* PopoverController */],
            __WEBPACK_IMPORTED_MODULE_1_ionic_angular__["a" /* ActionSheetController */],
            __WEBPACK_IMPORTED_MODULE_1_ionic_angular__["h" /* Platform */],
            __WEBPACK_IMPORTED_MODULE_2__ionic_native_camera__["a" /* Camera */],
            __WEBPACK_IMPORTED_MODULE_3__providers_drawing_drawing__["a" /* DrawingProvider */],
            __WEBPACK_IMPORTED_MODULE_7__angular_http__["a" /* Http */],
            __WEBPACK_IMPORTED_MODULE_1_ionic_angular__["g" /* LoadingController */],
            __WEBPACK_IMPORTED_MODULE_1_ionic_angular__["b" /* AlertController */]])
    ], HomePage);
    return HomePage;
}());

//# sourceMappingURL=home.js.map

/***/ }),

/***/ 197:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return ColorsPopoverPage; });
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_ionic_angular__ = __webpack_require__(30);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2__providers_drawing_drawing__ = __webpack_require__(42);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_3__fortawesome_free_solid_svg_icons__ = __webpack_require__(198);
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};




var ColorsPopoverPage = (function () {
    function ColorsPopoverPage(viewCtrl, drawing) {
        this.viewCtrl = viewCtrl;
        this.drawing = drawing;
        this.faCoffee = __WEBPACK_IMPORTED_MODULE_3__fortawesome_free_solid_svg_icons__["a" /* faCoffee */];
    }
    /**
     * Sets new brush color
     * @param color
     */
    ColorsPopoverPage.prototype.setColor = function (color) {
        this.drawing.changeBrushColor(color);
        this.viewCtrl.dismiss();
    };
    ColorsPopoverPage = __decorate([
        Object(__WEBPACK_IMPORTED_MODULE_0__angular_core__["m" /* Component */])({
            selector: 'page-colors-popover',template:/*ion-inline-start:"/home/node-5/production/painting/frontend/src/pages/colors-popover/colors-popover.html"*/'<div colors-container>\n  <button ion-button style="color:black" block *ngFor="let item of drawing.brushColors" [style.background]="item.color" (click)="setColor(item.color)">\n    {{item.title}} \n  </button>\n</div>\n'/*ion-inline-end:"/home/node-5/production/painting/frontend/src/pages/colors-popover/colors-popover.html"*/,
        }),
        __metadata("design:paramtypes", [__WEBPACK_IMPORTED_MODULE_1_ionic_angular__["j" /* ViewController */], __WEBPACK_IMPORTED_MODULE_2__providers_drawing_drawing__["a" /* DrawingProvider */]])
    ], ColorsPopoverPage);
    return ColorsPopoverPage;
}());

//# sourceMappingURL=colors-popover.js.map

/***/ }),

/***/ 199:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return WidthPopoverPage; });
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_ionic_angular__ = __webpack_require__(30);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2__providers_drawing_drawing__ = __webpack_require__(42);
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};



var WidthPopoverPage = (function () {
    function WidthPopoverPage(viewCtrl, drawing) {
        this.viewCtrl = viewCtrl;
        this.drawing = drawing;
    }
    /**
     * Sets new brush width
     * @param width
     */
    WidthPopoverPage.prototype.setWidth = function (width) {
        this.drawing.changeBrushWidth(width);
        this.viewCtrl.dismiss();
    };
    WidthPopoverPage = __decorate([
        Object(__WEBPACK_IMPORTED_MODULE_0__angular_core__["m" /* Component */])({
            selector: 'page-width-popover',template:/*ion-inline-start:"/home/node-5/production/painting/frontend/src/pages/width-popover/width-popover.html"*/'<ion-list>\n  <button *ngFor="let width of drawing.brushWidths"\n          ion-item\n          (click)="setWidth(width.value)"\n  >{{width.label}}</button>\n</ion-list>\n'/*ion-inline-end:"/home/node-5/production/painting/frontend/src/pages/width-popover/width-popover.html"*/,
        }),
        __metadata("design:paramtypes", [__WEBPACK_IMPORTED_MODULE_1_ionic_angular__["j" /* ViewController */], __WEBPACK_IMPORTED_MODULE_2__providers_drawing_drawing__["a" /* DrawingProvider */]])
    ], WidthPopoverPage);
    return WidthPopoverPage;
}());

//# sourceMappingURL=width-popover.js.map

/***/ }),

/***/ 200:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return BrushTypePopoverPage; });
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_ionic_angular__ = __webpack_require__(30);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2__providers_drawing_drawing__ = __webpack_require__(42);
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};



var BrushTypePopoverPage = (function () {
    function BrushTypePopoverPage(viewCtrl, drawing) {
        this.viewCtrl = viewCtrl;
        this.drawing = drawing;
    }
    /**
     * Sets new brush type
     * @param type
     */
    BrushTypePopoverPage.prototype.setType = function (type) {
        this.drawing.changeBrushType(type);
        this.viewCtrl.dismiss();
    };
    BrushTypePopoverPage = __decorate([
        Object(__WEBPACK_IMPORTED_MODULE_0__angular_core__["m" /* Component */])({
            selector: 'page-brush-type-popover',template:/*ion-inline-start:"/home/node-5/production/painting/frontend/src/pages/brush-type-popover/brush-type-popover.html"*/'<ion-list>\n  <button *ngFor="let type of drawing.brushTypes"\n          ion-item\n          (click)="setType(type.value)"\n  >{{type.label}}</button>\n</ion-list>\n'/*ion-inline-end:"/home/node-5/production/painting/frontend/src/pages/brush-type-popover/brush-type-popover.html"*/,
        }),
        __metadata("design:paramtypes", [__WEBPACK_IMPORTED_MODULE_1_ionic_angular__["j" /* ViewController */], __WEBPACK_IMPORTED_MODULE_2__providers_drawing_drawing__["a" /* DrawingProvider */]])
    ], BrushTypePopoverPage);
    return BrushTypePopoverPage;
}());

//# sourceMappingURL=brush-type-popover.js.map

/***/ }),

/***/ 203:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
Object.defineProperty(__webpack_exports__, "__esModule", { value: true });
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_platform_browser_dynamic__ = __webpack_require__(204);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__app_module__ = __webpack_require__(227);


Object(__WEBPACK_IMPORTED_MODULE_0__angular_platform_browser_dynamic__["a" /* platformBrowserDynamic */])().bootstrapModule(__WEBPACK_IMPORTED_MODULE_1__app_module__["a" /* AppModule */]);
//# sourceMappingURL=main.js.map

/***/ }),

/***/ 227:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return AppModule; });
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_platform_browser__ = __webpack_require__(21);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2_ionic_angular__ = __webpack_require__(30);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_3__ionic_native_splash_screen__ = __webpack_require__(192);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_4__ionic_native_status_bar__ = __webpack_require__(194);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_5__ionic_native_camera__ = __webpack_require__(195);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_6__providers_drawing_drawing__ = __webpack_require__(42);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_7__app_component__ = __webpack_require__(278);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_8__pages_home_home__ = __webpack_require__(196);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_9__pages_colors_popover_colors_popover__ = __webpack_require__(197);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_10__pages_width_popover_width_popover__ = __webpack_require__(199);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_11__pages_brush_type_popover_brush_type_popover__ = __webpack_require__(200);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_12__angular_http__ = __webpack_require__(201);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_13__fortawesome_angular_fontawesome__ = __webpack_require__(279);
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};














var AppModule = (function () {
    function AppModule() {
    }
    AppModule = __decorate([
        Object(__WEBPACK_IMPORTED_MODULE_1__angular_core__["I" /* NgModule */])({
            declarations: [
                __WEBPACK_IMPORTED_MODULE_7__app_component__["a" /* MyApp */],
                __WEBPACK_IMPORTED_MODULE_8__pages_home_home__["a" /* HomePage */],
                __WEBPACK_IMPORTED_MODULE_9__pages_colors_popover_colors_popover__["a" /* ColorsPopoverPage */],
                __WEBPACK_IMPORTED_MODULE_10__pages_width_popover_width_popover__["a" /* WidthPopoverPage */],
                __WEBPACK_IMPORTED_MODULE_11__pages_brush_type_popover_brush_type_popover__["a" /* BrushTypePopoverPage */],
            ],
            imports: [
                __WEBPACK_IMPORTED_MODULE_0__angular_platform_browser__["a" /* BrowserModule */],
                __WEBPACK_IMPORTED_MODULE_12__angular_http__["b" /* HttpModule */],
                __WEBPACK_IMPORTED_MODULE_2_ionic_angular__["f" /* IonicModule */].forRoot(__WEBPACK_IMPORTED_MODULE_7__app_component__["a" /* MyApp */], {}, {
                    links: []
                }),
                __WEBPACK_IMPORTED_MODULE_13__fortawesome_angular_fontawesome__["a" /* FontAwesomeModule */],
            ],
            bootstrap: [__WEBPACK_IMPORTED_MODULE_2_ionic_angular__["d" /* IonicApp */]],
            entryComponents: [
                __WEBPACK_IMPORTED_MODULE_7__app_component__["a" /* MyApp */],
                __WEBPACK_IMPORTED_MODULE_8__pages_home_home__["a" /* HomePage */],
                __WEBPACK_IMPORTED_MODULE_9__pages_colors_popover_colors_popover__["a" /* ColorsPopoverPage */],
                __WEBPACK_IMPORTED_MODULE_10__pages_width_popover_width_popover__["a" /* WidthPopoverPage */],
                __WEBPACK_IMPORTED_MODULE_11__pages_brush_type_popover_brush_type_popover__["a" /* BrushTypePopoverPage */],
            ],
            providers: [
                __WEBPACK_IMPORTED_MODULE_4__ionic_native_status_bar__["a" /* StatusBar */],
                __WEBPACK_IMPORTED_MODULE_3__ionic_native_splash_screen__["a" /* SplashScreen */],
                __WEBPACK_IMPORTED_MODULE_5__ionic_native_camera__["a" /* Camera */],
                { provide: __WEBPACK_IMPORTED_MODULE_1__angular_core__["u" /* ErrorHandler */], useClass: __WEBPACK_IMPORTED_MODULE_2_ionic_angular__["e" /* IonicErrorHandler */] },
                __WEBPACK_IMPORTED_MODULE_6__providers_drawing_drawing__["a" /* DrawingProvider */],
            ]
        })
    ], AppModule);
    return AppModule;
}());

//# sourceMappingURL=app.module.js.map

/***/ }),

/***/ 278:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return MyApp; });
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_ionic_angular__ = __webpack_require__(30);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2__ionic_native_status_bar__ = __webpack_require__(194);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_3__ionic_native_splash_screen__ = __webpack_require__(192);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_4__pages_home_home__ = __webpack_require__(196);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_5__fortawesome_free_solid_svg_icons__ = __webpack_require__(198);
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};






var MyApp = (function () {
    function MyApp(platform, statusBar, splashScreen) {
        this.rootPage = __WEBPACK_IMPORTED_MODULE_4__pages_home_home__["a" /* HomePage */];
        this.faCoffee = __WEBPACK_IMPORTED_MODULE_5__fortawesome_free_solid_svg_icons__["a" /* faCoffee */];
        platform.ready().then(function () {
            // Okay, so the platform is ready and our plugins are available.
            // Here you can do any higher level native things you might need.
            statusBar.styleDefault();
            splashScreen.hide();
        });
    }
    MyApp = __decorate([
        Object(__WEBPACK_IMPORTED_MODULE_0__angular_core__["m" /* Component */])({template:/*ion-inline-start:"/home/node-5/production/painting/frontend/src/app/app.html"*/'<ion-nav [root]="rootPage"></ion-nav>\n<div style="text-align:center">\n    <fa-icon [icon]="faCoffee"></fa-icon>\n  </div>'/*ion-inline-end:"/home/node-5/production/painting/frontend/src/app/app.html"*/
        }),
        __metadata("design:paramtypes", [__WEBPACK_IMPORTED_MODULE_1_ionic_angular__["h" /* Platform */], __WEBPACK_IMPORTED_MODULE_2__ionic_native_status_bar__["a" /* StatusBar */], __WEBPACK_IMPORTED_MODULE_3__ionic_native_splash_screen__["a" /* SplashScreen */]])
    ], MyApp);
    return MyApp;
}());

//# sourceMappingURL=app.component.js.map

/***/ }),

/***/ 42:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "a", function() { return DrawingProvider; });
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__angular_core__ = __webpack_require__(0);
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};

var DrawingProvider = (function () {
    function DrawingProvider() {
        /**
         * Default brush color
         * @type {string}
         */
        this.brushColor = '#b7d24e';
        this.brushTitle = 'Grass';
        /**
         * Default brush width
         * @type {number}
         */
        this.brushWidth = 15;
        /**
         * List of available brush colors
         * @type {}
         */
        this.brushColors = [
            { color: "#384f83", title: "Sea" },
            { color: "#efefef", title: "Cloud" },
            { color: "#2c1e16", title: "Dirt" },
            { color: "#5d6e32", title: "Bush" },
            { color: "#b7d24e", title: "Grass" },
            { color: "#3c3b4b", title: "Mountain" },
            { color: "#987e6a", title: "Road" },
            { color: "#759edf", title: "Sky" },
            { color: "#352613", title: "Tree" },
            { color: "#636363", title: "Pavement" },
            { color: "#e670b6", title: "Flower" },
            { color: "#c1c3c9", title: "Fog" },
            { color: "#776c2d", title: "Hill" },
            { color: "#bf602c", title: "Leaves" },
            { color: "#32604d", title: "River" },
            { color: "#fafafa", title: "Snow" },
            { color: "#7CFC00", title: "Airplane" },
            { color: "#D2D2D2", title: "Boat" },
            { color: "#D2691E", title: "Bridge" },
            { color: "#8B0000", title: "Roof*" },
            { color: "#DEB887", title: "House" },
            { color: "#00CED1", title: "Window" },
            { color: "#B22222", title: "Brick Wall" },
            { color: "#8B4513", title: "Branch" }
            // { color: "#FF3232", title: "fire" }
        ];
        /**
         * List of available brush widths
         * @type {}
         */
        this.brushWidths = [
            { value: 1, label: '1px' },
            { value: 2, label: '2px' },
            { value: 3, label: '3px' },
            { value: 4, label: '4px' },
            { value: 5, label: '5px' },
            { value: 6, label: '6px' },
            { value: 7, label: '7px' },
            { value: 8, label: '8px' },
            { value: 9, label: '9px' },
            { value: 10, label: '10px' },
            { value: 12, label: '12px' },
            { value: 15, label: '15px' },
            { value: 20, label: '20px' },
            { value: 25, label: '25px' },
            { value: 30, label: '30px' },
            { value: 60, label: '60px' },
        ];
        /**
         * List of available brush types
         * @type {}
         */
        this.brushTypes = [
            { value: 'Pencil', label: 'Pencil' },
            { value: 'Circle', label: 'Circle' },
            { value: 'Spray', label: 'Spray' },
            { value: 'Pattern', label: 'Pattern' },
            { value: 'hline', label: 'Horizontal lines' },
            { value: 'vline', label: 'Vertical lines' },
            { value: 'square', label: 'Square' },
            { value: 'diamond', label: 'Diamond' },
            { value: 'texture', label: 'Texture' },
        ];
    }
    /**
     * Returns drawing as base64 string
     * @returns {string}
     */
    DrawingProvider.prototype.getAsImage = function () {
        return this.canvas.toDataURL({
            format: 'png',
        });
    };
    /**
     * Disabled drawing on canvas
     */
    DrawingProvider.prototype.disableDrawing = function () {
        this.canvas.isDrawingMode = false;
    };
    /**
     * Enables drawing on canvas
     */
    DrawingProvider.prototype.enableDrawing = function () {
        this.canvas.isDrawingMode = true;
    };
    /**
     * Creates canvas for drawing on it
     * @param {number} width
     * @param {number} height
     */
    DrawingProvider.prototype.create = function (width, height) {
        this.width = width;
        this.height = height;
        // make sure "drawing-container" value matches your container for drawing
        this.canvas = new fabric.Canvas('drawing-container', { backgroundColor: "#585858" });
        // prevent drawing objects to be draggable or clickable
        this.canvas.selection = false;
        fabric.Object.prototype.selectable = false;
        // sets canvas height and width
        this.canvas.setHeight(this.height);
        this.canvas.setWidth(this.width);
        // sets canvas height and width
        // *** having both canvas.setHeight and canvas.width prevents errors when saving
        this.canvas.width = this.width;
        this.canvas.height = this.height;
        // set size and color of the drawing brush
        this.canvas.freeDrawingBrush.width = this.brushWidth;
        this.canvas.freeDrawingBrush.color = this.brushColor;
        // make sure drawing is enabled
        this.enableDrawing();
    };
    /**
     * Change brush color
     * @param color
     */
    DrawingProvider.prototype.changeBrushColor = function (color) {
        var _this = this;
        this.brushColor = color;
        this.canvas.freeDrawingBrush.color = this.brushColor;
        var index = this.brushColors.findIndex(function (obj) { return obj.color == _this.brushColor; });
        this.brushTitle = this.brushColors[index].title;
    };
    /**
     * Change brush width
     * @param {number} width
     */
    DrawingProvider.prototype.changeBrushWidth = function (width) {
        this.brushWidth = width;
        this.canvas.freeDrawingBrush.width = this.brushWidth;
    };
    DrawingProvider.prototype.changeBackgroundColor = function (color) {
        this.canvas.backgroundColor = color;
    };
    /**
     * Change brush type
     * @param type
     */
    DrawingProvider.prototype.changeBrushType = function (type) {
        if (type === 'hline') {
            this.canvas.freeDrawingBrush = this.getHLinePatternBrush();
        }
        else if (type === 'vline') {
            this.canvas.freeDrawingBrush = this.getVLinePatternBrush();
        }
        else if (type === 'square') {
            this.canvas.freeDrawingBrush = this.getSquarePatternBrush();
        }
        else if (type === 'diamond') {
            this.canvas.freeDrawingBrush = this.getDiamondPatternBrush();
        }
        else if (type === 'texture') {
            this.canvas.freeDrawingBrush = this.getTexturePatternBrush();
        }
        else {
            this.canvas.freeDrawingBrush = new fabric[type + 'Brush'](this.canvas);
        }
        if (this.canvas.freeDrawingBrush) {
            this.canvas.freeDrawingBrush.color = this.brushColor;
            this.canvas.freeDrawingBrush.width = this.brushWidth;
        }
    };
    /**
     * Adds text on canvas
     * @param {string} text
     */
    DrawingProvider.prototype.addText = function (text) {
        this.disableDrawing();
        var t = new fabric.Text(text, {
            left: (this.width / 3),
            top: 100,
            fontFamily: 'Helvetica',
            fill: this.brushColor,
            selectable: true,
        });
        this.canvas.add(t);
    };
    /**
     * Adds image on canvas
     * @param imageSrc
     */
    DrawingProvider.prototype.addImage = function (imageSrc) {
        var _this = this;
        this.disableDrawing();
        var image = new Image();
        image.setAttribute('crossOrigin', 'anonymous');
        image.onload = function () {
            var imgInstance = new fabric.Image(image, {
                left: 0,
                top: 100,
                selectable: true,
                transparentCorners: false,
                scaleX: 1.0,
                scaleY: 1.0
            });
            _this.canvas.add(imgInstance);
            _this.canvas.renderAll();
            _this.canvas.setActiveObject(imgInstance);
        };
        image.src = imageSrc;
        // make sure the load event fires for cached images too
        if (image.complete || image.complete === undefined) {
            image.src = 'data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///ywAAAAAAQABAAACAUwAOw==';
            image.src = imageSrc;
        }
    };
    /**
     * Adds canvas background
     * @param {string} imageSrc
     */
    DrawingProvider.prototype.addBackgroundImage = function (imageSrc) {
        var _this = this;
        var image = new Image();
        image.setAttribute('crossOrigin', 'anonymous');
        // we need to get real image size and make sure it fits on screen
        image.onload = function () {
            var width = image.width;
            var height = image.height;
            var scaleX;
            var scaleY;
            if (width > height) {
                scaleX = _this.width / width;
                scaleY = _this.height / (_this.height * width / _this.width);
            }
            else {
                scaleX = _this.width / (_this.width * height / _this.height);
                scaleY = _this.height / height;
            }
            var center = _this.canvas.getCenter();
            _this.canvas.setBackgroundImage(imageSrc, _this.canvas.renderAll.bind(_this.canvas), {
                scaleX: scaleX,
                scaleY: scaleY,
                originX: 'center',
                originY: 'center',
                top: center.top,
                left: center.left,
                crossOrigin: 'anonymous'
            });
        };
        image.src = imageSrc;
        // make sure the load event fires for cached images too
        if (image.complete || image.complete === undefined) {
            image.src = 'data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///ywAAAAAAQABAAACAUwAOw==';
            image.src = imageSrc;
        }
    };
    DrawingProvider.prototype.setCanvas = function (imageSrc) {
        var _this = this;
        this.disableDrawing();
        this.canvas.clear();
        var image = new Image();
        image.setAttribute('crossOrigin', 'anonymous');
        // we need to get real image size and make sure it fits on screen
        image.onload = function () {
            var width = image.width;
            var height = image.height;
            var scaleX;
            var scaleY;
            if (width > height) {
                scaleX = _this.width / width;
                scaleY = _this.height / (_this.height * width / _this.width);
            }
            else {
                scaleX = _this.width / (_this.width * height / _this.height);
                scaleY = _this.height / height;
            }
            var center = _this.canvas.getCenter();
            _this.canvas.setBackgroundImage(imageSrc, _this.canvas.renderAll.bind(_this.canvas), {
                scaleX: scaleX,
                scaleY: scaleY,
                originX: 'center',
                originY: 'center',
                top: center.top,
                left: center.left,
                crossOrigin: 'anonymous'
            });
        };
        image.src = imageSrc;
        // make sure the load event fires for cached images too
        if (image.complete || image.complete === undefined) {
            image.src = 'data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///ywAAAAAAQABAAACAUwAOw==';
            image.src = imageSrc;
        }
    };
    /**
     * Undo change on canvas
     */
    DrawingProvider.prototype.undo = function () {
        var canvas_objects = this.canvas._objects;
        var last = canvas_objects[canvas_objects.length - 1];
        this.canvas.remove(last);
        this.canvas.renderAll();
    };
    /**
     * Returns hLine pattern brush
     * @returns {fabric.PatternBrush}
     */
    DrawingProvider.prototype.getHLinePatternBrush = function () {
        var vLinePatternBrush = new fabric.PatternBrush(this.canvas);
        fabric.PatternBrush.color = this.brushColor;
        vLinePatternBrush.getPatternSrc = function () {
            var patternCanvas = fabric.document.createElement('canvas');
            patternCanvas.width = patternCanvas.height = 10;
            var ctx = patternCanvas.getContext('2d');
            ctx.strokeStyle = this.color;
            ctx.lineWidth = 5;
            ctx.beginPath();
            ctx.moveTo(0, 5);
            ctx.lineTo(10, 5);
            ctx.closePath();
            ctx.stroke();
            return patternCanvas;
        };
        return vLinePatternBrush;
    };
    /**
     * Returns vLine pattern brush
     * @returns {fabric.PatternBrush}
     */
    DrawingProvider.prototype.getVLinePatternBrush = function () {
        var hLinePatternBrush = new fabric.PatternBrush(this.canvas);
        fabric.PatternBrush.color = this.brushColor;
        hLinePatternBrush.getPatternSrc = function () {
            var patternCanvas = fabric.document.createElement('canvas');
            patternCanvas.width = patternCanvas.height = 10;
            var ctx = patternCanvas.getContext('2d');
            ctx.strokeStyle = this.color;
            ctx.lineWidth = 5;
            ctx.beginPath();
            ctx.moveTo(5, 0);
            ctx.lineTo(5, 10);
            ctx.closePath();
            ctx.stroke();
            return patternCanvas;
        };
        return hLinePatternBrush;
    };
    /**
     * Returns square pattern brush
     * @returns {fabric.PatternBrush}
     */
    DrawingProvider.prototype.getSquarePatternBrush = function () {
        var squarePatternBrush = new fabric.PatternBrush(this.canvas);
        fabric.PatternBrush.color = this.brushColor;
        squarePatternBrush.getPatternSrc = function () {
            var squareWidth = 10, squareDistance = 2;
            var patternCanvas = fabric.document.createElement('canvas');
            patternCanvas.width = patternCanvas.height = squareWidth + squareDistance;
            var ctx = patternCanvas.getContext('2d');
            ctx.fillStyle = this.color;
            ctx.fillRect(0, 0, squareWidth, squareWidth);
            return patternCanvas;
        };
        return squarePatternBrush;
    };
    /**
     * Returns diamond pattern brush
     * @returns {fabric.PatternBrush}
     */
    DrawingProvider.prototype.getDiamondPatternBrush = function () {
        var diamondPatternBrush = new fabric.PatternBrush(this.canvas);
        fabric.PatternBrush.color = this.brushColor;
        diamondPatternBrush.getPatternSrc = function () {
            var squareWidth = 10, squareDistance = 5;
            var patternCanvas = fabric.document.createElement('canvas');
            var rect = new fabric.Rect({
                width: squareWidth,
                height: squareWidth,
                angle: 45,
                fill: this.color
            });
            var canvasWidth = rect.getBoundingRect().width;
            patternCanvas.width = patternCanvas.height = canvasWidth + squareDistance;
            rect.set({ left: canvasWidth / 2, top: canvasWidth / 2 });
            var ctx = patternCanvas.getContext('2d');
            rect.render(ctx);
            return patternCanvas;
        };
        return diamondPatternBrush;
    };
    /**
     * Returns diamond pattern brush
     * @returns {fabric.PatternBrush}
     */
    DrawingProvider.prototype.getTexturePatternBrush = function () {
        var img = new Image();
        img.src = '../assets/imgs/texture.png';
        var texturePatternBrush = new fabric.PatternBrush(this.canvas);
        texturePatternBrush.source = img;
        return texturePatternBrush;
    };
    DrawingProvider = __decorate([
        Object(__WEBPACK_IMPORTED_MODULE_0__angular_core__["A" /* Injectable */])(),
        __metadata("design:paramtypes", [])
    ], DrawingProvider);
    return DrawingProvider;
}());

//# sourceMappingURL=drawing.js.map

/***/ })

},[203]);
//# sourceMappingURL=main.js.map