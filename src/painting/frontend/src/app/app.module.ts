import { BrowserModule } from '@angular/platform-browser';
import { ErrorHandler, NgModule } from '@angular/core';
import { IonicApp, IonicErrorHandler, IonicModule } from 'ionic-angular';
import { SplashScreen } from '@ionic-native/splash-screen';
import { StatusBar } from '@ionic-native/status-bar';
import { Camera } from '@ionic-native/camera';
import { DrawingProvider } from '../providers/drawing/drawing';

import { MyApp } from './app.component';
import { HomePage } from '../pages/home/home';
import { ColorsPopoverPage } from '../pages/colors-popover/colors-popover';
import { WidthPopoverPage } from '../pages/width-popover/width-popover';
import { BrushTypePopoverPage } from '../pages/brush-type-popover/brush-type-popover';

import { HttpModule } from '@angular/http';
import { FontAwesomeModule } from '@fortawesome/angular-fontawesome';

@NgModule({
  declarations: [
    MyApp,
    HomePage,
    ColorsPopoverPage,
    WidthPopoverPage,
    BrushTypePopoverPage,
  ],
  imports: [
    BrowserModule,
    HttpModule,
    IonicModule.forRoot(MyApp),
    FontAwesomeModule,
  ],
  bootstrap: [IonicApp],
  entryComponents: [
    MyApp,
    HomePage,
    ColorsPopoverPage,
    WidthPopoverPage,
    BrushTypePopoverPage,
  ],
  providers: [
    StatusBar,
    SplashScreen,
    Camera,
    {provide: ErrorHandler, useClass: IonicErrorHandler},
    DrawingProvider,
  ]
})
export class AppModule {}
