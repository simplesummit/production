import { Injectable } from '@angular/core';
declare let fabric;

@Injectable()
export class DrawingProvider {
  public canvas: any;
  public width: number;
  public height: number;

  /**
   * Default brush color
   * @type {string}
   */
  public brushColor: string = '#b7d24e';
  public brushTitle: string = 'Grass'

  /**
   * Default brush width
   * @type {number}
   */
  public brushWidth: number = 15;

  /**
   * List of available brush colors
   * @type {}
   */ 
  
  brushColors = [
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
  public brushWidths = [
    {value: 1, label: '1px'},
    {value: 2, label: '2px'},
    {value: 3, label: '3px'},
    {value: 4, label: '4px'},
    {value: 5, label: '5px'},
    {value: 6, label: '6px'},
    {value: 7, label: '7px'},
    {value: 8, label: '8px'},
    {value: 9, label: '9px'},
    {value: 10, label: '10px'},
    {value: 12, label: '12px'},
    {value: 15, label: '15px'},
    {value: 20, label: '20px'},
    {value: 25, label: '25px'},
    {value: 30, label: '30px'},
    {value: 60, label: '60px'},
  ];

  /**
   * List of available brush types
   * @type {}
   */
  public brushTypes = [
    {value: 'Pencil', label: 'Pencil'},
    {value: 'Circle', label: 'Circle'},
    {value: 'Spray', label: 'Spray'},
    {value: 'Pattern', label: 'Pattern'},
    {value: 'hline', label: 'Horizontal lines'},
    {value: 'vline', label: 'Vertical lines'},
    {value: 'square', label: 'Square'},
    {value: 'diamond', label: 'Diamond'},
    {value: 'texture', label: 'Texture'},
  ];

  constructor() {
  }

  /**
   * Returns drawing as base64 string
   * @returns {string}
   */
  getAsImage() {
    return this.canvas.toDataURL({
      format: 'png',
    });
  }

  /**
   * Disabled drawing on canvas
   */
  disableDrawing() {
    this.canvas.isDrawingMode = false;
  }

  /**
   * Enables drawing on canvas
   */
  enableDrawing() {
    this.canvas.isDrawingMode = true;
  }

  /**
   * Creates canvas for drawing on it
   * @param {number} width
   * @param {number} height
   */
  create(width: number, height: number) {
    this.width  = width;
    this.height = height;

    // make sure "drawing-container" value matches your container for drawing
    this.canvas = new fabric.Canvas('drawing-container' ,{backgroundColor : "#585858"});

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
  }

  /**
   * Change brush color
   * @param color
   */
  changeBrushColor(color: string) {
    this.brushColor = color;
    this.canvas.freeDrawingBrush.color = this.brushColor;
    let index = this.brushColors.findIndex(obj => obj.color==this.brushColor);
    this.brushTitle = this.brushColors[index].title;
  }

  /**
   * Change brush width
   * @param {number} width
   */
  changeBrushWidth(width: number) {
    this.brushWidth = width;
    this.canvas.freeDrawingBrush.width = this.brushWidth;
  }


  changeBackgroundColor(color : string) {
    this.canvas.backgroundColor = color;
  }
  /**
   * Change brush type
   * @param type
   */
  changeBrushType(type) {
    if (type === 'hline') {
      this.canvas.freeDrawingBrush = this.getHLinePatternBrush();
    } else if (type === 'vline') {
      this.canvas.freeDrawingBrush = this.getVLinePatternBrush();
    } else if (type === 'square') {
      this.canvas.freeDrawingBrush = this.getSquarePatternBrush();
    } else if (type === 'diamond') {
      this.canvas.freeDrawingBrush = this.getDiamondPatternBrush();
    } else if (type === 'texture') {
      this.canvas.freeDrawingBrush = this.getTexturePatternBrush();
    } else {
      this.canvas.freeDrawingBrush = new fabric[type + 'Brush'](this.canvas);
    }

    if (this.canvas.freeDrawingBrush) {
      this.canvas.freeDrawingBrush.color = this.brushColor;
      this.canvas.freeDrawingBrush.width = this.brushWidth;
    }
  }

  /**
   * Adds text on canvas
   * @param {string} text
   */
  addText(text: string) {
    this.disableDrawing();

    let t = new fabric.Text(text, {
      left: (this.width / 3),
      top: 100,
      fontFamily: 'Helvetica',
      fill: this.brushColor,
      selectable: true,

    });
    this.canvas.add(t);
  }

  /**
   * Adds image on canvas
   * @param imageSrc
   */
  addImage(imageSrc: string) {
    this.disableDrawing();

    let image = new Image();
    image.setAttribute('crossOrigin', 'anonymous');

    image.onload = () => {
      let imgInstance = new fabric.Image(image, {
        left: 0,
        top: 100,
        selectable: true,
        transparentCorners: false,
        scaleX: 1.0,
        scaleY: 1.0
      });
      this.canvas.add(imgInstance);
      this.canvas.renderAll();
      this.canvas.setActiveObject(imgInstance);
    };
    image.src = imageSrc;

    // make sure the load event fires for cached images too
    if (image.complete || image.complete === undefined) {
      image.src = 'data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///ywAAAAAAQABAAACAUwAOw==';
      image.src = imageSrc;
    }
  }

  /**
   * Adds canvas background
   * @param {string} imageSrc
   */
  addBackgroundImage(imageSrc: string) {
    let image = new Image();
    image.setAttribute('crossOrigin', 'anonymous');

    // we need to get real image size and make sure it fits on screen
    image.onload = () => {
      let width   = image.width;
      let height  = image.height;

      let scaleX;
      let scaleY;

      if (width > height) {
        scaleX = this.width / width;
        scaleY = this.height / (this.height * width / this.width);
      } else {
        scaleX = this.width / (this.width * height / this.height);
        scaleY = this.height / height;
      }

      let center = this.canvas.getCenter();
      this.canvas.setBackgroundImage(imageSrc, this.canvas.renderAll.bind(this.canvas), {
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
  }

  setCanvas(imageSrc: string) {
    this.disableDrawing();
    this.canvas.clear();
    let image = new Image();
    image.setAttribute('crossOrigin', 'anonymous');

    // we need to get real image size and make sure it fits on screen
    image.onload = () => {
      let width   = image.width;
      let height  = image.height;

      let scaleX;
      let scaleY;

      if (width > height) {
        scaleX = this.width / width;
        scaleY = this.height / (this.height * width / this.width);
      } else {
        scaleX = this.width / (this.width * height / this.height);
        scaleY = this.height / height;
      }

      let center = this.canvas.getCenter();
      this.canvas.setBackgroundImage(imageSrc, this.canvas.renderAll.bind(this.canvas), {
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
  }

  /**
   * Undo change on canvas
   */
  undo() {
    let canvas_objects = this.canvas._objects;
    let last = canvas_objects[canvas_objects.length - 1];
    this.canvas.remove(last);
    this.canvas.renderAll();
  }

  /**
   * Returns hLine pattern brush
   * @returns {fabric.PatternBrush}
   */
  private getHLinePatternBrush() {
    let vLinePatternBrush = new fabric.PatternBrush(this.canvas);
    fabric.PatternBrush.color = this.brushColor;

    vLinePatternBrush.getPatternSrc = function() {
      let patternCanvas = fabric.document.createElement('canvas');
      patternCanvas.width = patternCanvas.height = 10;
      let ctx = patternCanvas.getContext('2d');

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
  }

  /**
   * Returns vLine pattern brush
   * @returns {fabric.PatternBrush}
   */
  private getVLinePatternBrush() {
    let hLinePatternBrush = new fabric.PatternBrush(this.canvas);
    fabric.PatternBrush.color = this.brushColor;

    hLinePatternBrush.getPatternSrc = function () {

      let patternCanvas = fabric.document.createElement('canvas');
      patternCanvas.width = patternCanvas.height = 10;
      let ctx = patternCanvas.getContext('2d');

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
  }

  /**
   * Returns square pattern brush
   * @returns {fabric.PatternBrush}
   */
  private getSquarePatternBrush() {
    let squarePatternBrush = new fabric.PatternBrush(this.canvas);
    fabric.PatternBrush.color = this.brushColor;

    squarePatternBrush.getPatternSrc = function() {
      let squareWidth = 10, squareDistance = 2;

      let patternCanvas = fabric.document.createElement('canvas');
      patternCanvas.width = patternCanvas.height = squareWidth + squareDistance;
      let ctx = patternCanvas.getContext('2d');

      ctx.fillStyle = this.color;
      ctx.fillRect(0, 0, squareWidth, squareWidth);

      return patternCanvas;
    };

    return squarePatternBrush;
  }

  /**
   * Returns diamond pattern brush
   * @returns {fabric.PatternBrush}
   */
  private getDiamondPatternBrush() {
    let diamondPatternBrush = new fabric.PatternBrush(this.canvas);
    fabric.PatternBrush.color = this.brushColor;

    diamondPatternBrush.getPatternSrc = function() {
      let squareWidth = 10, squareDistance = 5;
      let patternCanvas = fabric.document.createElement('canvas');
      let rect = new fabric.Rect({
        width: squareWidth,
        height: squareWidth,
        angle: 45,
        fill: this.color
      });

      let canvasWidth = rect.getBoundingRect().width;

      patternCanvas.width = patternCanvas.height = canvasWidth + squareDistance;
      rect.set({ left: canvasWidth / 2, top: canvasWidth / 2 });

      let ctx = patternCanvas.getContext('2d');
      rect.render(ctx);

      return patternCanvas;
    };

    return diamondPatternBrush;
  }

  /**
   * Returns diamond pattern brush
   * @returns {fabric.PatternBrush}
   */
  private getTexturePatternBrush() {
    let img = new Image();
    img.src = '../assets/imgs/texture.png';

    let texturePatternBrush = new fabric.PatternBrush(this.canvas);
    texturePatternBrush.source = img;

    return texturePatternBrush;
  }
}
