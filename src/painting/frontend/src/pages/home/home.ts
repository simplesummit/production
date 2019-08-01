import { Component, ViewChild } from '@angular/core';
import { ActionSheetController, AlertController, Content, PopoverController, Platform, LoadingController } from 'ionic-angular';
import { Camera } from '@ionic-native/camera';
import { DrawingProvider } from '../../providers/drawing/drawing';
import { ColorsPopoverPage } from '../colors-popover/colors-popover';
import { WidthPopoverPage } from '../width-popover/width-popover';
import { BrushTypePopoverPage } from '../brush-type-popover/brush-type-popover';
import { Http, Headers, RequestOptions} from '@angular/http';

@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})
export class HomePage {
  @ViewChild(Content) content: Content;
  public drawingEnabled: boolean = true;

  constructor(
    public popoverCtrl: PopoverController,
    public actionSheetCtrl: ActionSheetController,
    public platform: Platform,
    public camera: Camera,
    public drawing: DrawingProvider,
    public http: Http,
    public loadingCtrl: LoadingController,
    private alertCtrl: AlertController,
  ) {
  }

  text = 'Use Artificial Intellgence to create Photorealistic Paintings on your Phone!';
  url = 'https://loganoneal.com';
  host = 'http://localhost:80/'

  //Alert Functions
  reset() {
    let alert = this.alertCtrl.create({
      title: 'Confirm New',
      message: 'Are you sure you want to start a new painting?',
      buttons: [
        {
          text: 'Yes',
          role: 'yes',
          handler: () => {
	  	      this.drawing.canvas.clear()
            this.drawingEnabled = true;
          }
        },
        {
          text: 'Cancel',
          role: 'cancel',
          handler: () => {
	  console.log('Cancel clicked');
	  this.drawingEnabled = true;
          }
        }
      ],
      cssClass: "alertCss",
    });
    alert.present()
    console.log('reset');
  }
  loading = this.loadingCtrl.create({
    spinner: 'hide',
    content: `<img src="assets/imgs/loading.gif"/> Painting Your Masterpiece...`,
  });

  presentLoadingCustom() {

    this.loading.onDidDismiss(() => {
      console.log('Dismissed loading');
    });
    this.loading.present();
  }


  /**
   * Make sure you are calling create method inside of "ionViewDidLoad"
   */
  ionViewDidLoad() {
    // we are here taking full screen for drawing, change this logic if you need something else
    let width   = window.screen.width
    let height = window.screen.height

    this.drawing.create(width, height);
    }

  /**
   * In this method you can do something with your drawing
   */

  upload() {
    // drawing variable is base64 image
    let drawing = this.drawing.getAsImage();

    this.presentLoadingCustom();
    /*
    var headers = new Headers();
      headers.append('Access-Control-Allow-Origin' , 'http://localhost:80/upload');
      headers.append('Access-Control-Allow-Methods', 'POST, GET, OPTIONS, PUT');
      headers.append('Accept','application/json');
      headers.append('content-type','application/json');
      let options = new RequestOptions({ headers:headers,withCredentials: false});*/
    let postData = drawing;
    this.http.post(this.host + "upload", postData)
      .subscribe(data => {
        console.log(data['_body']);
        let dataB = data.json();
        console.log("Location: " + " " + dataB['location'] + "\n");
        let imageSource = dataB['location'];
        this.drawing.setCanvas(this.host+ imageSource);
        this.loading.dismiss();
      }, error => {
        console.log(error);
      });
  }

  /**
   * Switch back to drawing
   */
  ok() {
    this.drawingEnabled = true;
    this.drawing.enableDrawing();
  }

  /**
   * Displays list of colors
   * @param event
   */
  openColorsPopover(event) {
    let popover = this.popoverCtrl.create(ColorsPopoverPage);
    popover.present({
      ev: event
    });
  }

  /**
   * Displays list of brush widths
   * @param event
   */
  openWidthsPopover(event) {
    let popover = this.popoverCtrl.create(WidthPopoverPage);
    popover.present({
      ev: event
    });
  }

  /**
   * Displays list of brush types
   * @param event
   */
  openTypesPopover(event) {
    let popover = this.popoverCtrl.create(BrushTypePopoverPage);
    popover.present({
      ev: event
    });
  }

  /**
   * Adds text
   */
  addText() {
    let alert = this.alertCtrl.create({
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
          handler: () => {}
        },
        {
          text: 'OK',
          handler: (data) => {
            if (data.text === "")
              return false;

            // when adding text we need to disable drawing so that is possible
            // to manage text on screen
            this.drawingEnabled = true;
            this.drawing.addText(data.text);
          }
        }
      ]
    });

    alert.present();
  }

  /**
   * Adds image to canvas
   */
  addImage() {
    let actionSheet = this.actionSheetCtrl.create({
      title: 'Add photo',
      buttons: [
        {
          text: 'Take picture',
          icon: 'camera',
          handler: () => {
            this.takePicture(true)
              .then(
                (image: string) => {
                  this.drawingEnabled = true;
                  this.drawing.addImage(image);
                }
              )
              .catch(() => {})
            ;
          }
        },{
          text: 'Select from gallery',
          icon: 'image',
          handler: () => {
            this.takePicture(false)
              .then(
                (image: string) => {
                  this.drawingEnabled = true;
                  this.drawing.addImage(image);
                }
              )
              .catch(() => {})
            ;
          }
        },{
          text: 'Cancel',
          icon: 'close',
          handler: () => {}
        }
      ]
    });

    actionSheet.present();
  }

  /**
   * Adds background to canvas
   */
  addBackground() {
    let actionSheet = this.actionSheetCtrl.create({
      title: 'Add background',
      buttons: [
        {
          text: 'Take picture',
          icon: 'camera',
          handler: () => {
            this.takePicture(true)
              .then(
                (image: string) => {
                  this.drawing.addBackgroundImage(image);
                }
              ).catch(() => {})
            ;
          }
        },{
          text: 'Select from gallery',
          icon: 'image',
          handler: () => {
            this.takePicture(false)
              .then(
                (image: string) => {
                  this.drawing.addBackgroundImage(image);
                }
              )
              .catch(() => {})
            ;
          }
        },{
          text: 'Cancel',
          icon: 'close',
          handler: () => {}
        }
      ]
    });

    actionSheet.present();
  }

  /**
   * Undo last change
   */
  undo() {
    this.drawing.undo();
  }

  /**
   * Takes image from camera or photo gallery
   * @param from_camera
   */
  private takePicture(from_camera) {
    return new Promise((resolve, reject) => {

      // define camera options
      let options = {
        quality           : 50,
        allowEdit         : true,
        saveToPhotoAlbum  : false,
        cameraDirection   : 0,
        correctOrientation: true,
        targetWidth       : 1200,
        targetHeight      : 800,
        sourceType        : from_camera ? this.camera.PictureSourceType.CAMERA : this.camera.PictureSourceType.PHOTOLIBRARY,
        destinationType   : this.camera.DestinationType.DATA_URL,
        encodingType      : this.camera.EncodingType.JPEG
      };

      this.camera.getPicture(options).then(
        (image) => resolve('data:image/jpeg;base64,' + image),
        () => reject()
      );
    });
  }
}
