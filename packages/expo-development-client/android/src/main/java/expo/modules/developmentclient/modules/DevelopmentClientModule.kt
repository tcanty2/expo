package expo.modules.developmentclient.modules

import android.content.Intent
import android.provider.MediaStore
import com.facebook.react.bridge.Promise
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.bridge.ReactContextBaseJavaModule
import com.facebook.react.bridge.ReactMethod
import com.facebook.react.bridge.ReadableMap
import expo.modules.developmentclient.DevelopmentClientController.Companion.instance

private val cameraPackages = listOf(
  "com.sec.android.app.camera",
  "com.android.app.camera",
  "com.android.camera",
  "com.mediatek.camera",
  "com.android.camera2",
  "com.android.app.camera2",
  "com.meizu.media.camera",
  "com.htc.camera",
  "com.oppo.camera",
  "com.lge.camera",
  "com.google.android.GoogleCamera",
  "com.motorola.Camera",
  "com.google.android.camera",
  "com.sonyericsson.android.camera",
  "com.samsung.android.camera"
)

class DevelopmentClientModule(reactContext: ReactApplicationContext?) : ReactContextBaseJavaModule(reactContext) {
  override fun getName(): String {
    return "EXDevelopmentClient"
  }

  override fun hasConstants(): Boolean {
    return true
  }

  @ReactMethod
  fun loadApp(url: String?, options: ReadableMap?, promise: Promise) {
    instance.loadApp(url)
    promise.resolve(null)
  }

  @ReactMethod
  fun openCamera(promise: Promise) {
    val packageManager = reactApplicationContext.packageManager

    // We can't just trigger default intent for camera, because we don't have `CAMERA` permissions.
    // Firstly, we try to get a package that handles the default camera intent...
    Intent(MediaStore.ACTION_IMAGE_CAPTURE)
      .resolveActivity(packageManager)
      ?.let { componentName ->
      // ...then we search for the launcher intent.
      // However, this approach might fail...
      packageManager
        .getLaunchIntentForPackage(componentName.packageName)
        ?.let {
          reactApplicationContext.startActivity(it)
          promise.resolve(null)
          return
        }
    }

    // ...if so, we can fallback to the hardcoded packages list.
    // A lot of custom ROMs do it in the same way.
    cameraPackages.forEach { cameraPackage ->
      reactApplicationContext
        .packageManager
        .getLaunchIntentForPackage(cameraPackage)
        ?.let {
          reactApplicationContext.startActivity(it)
          promise.resolve(null)
          return
        }
    }
    promise.reject("ERR_DEVELOPMENT_CLIENT_CANNOT_OPEN_CAMERA", "Couldn't find the camera app.")
  }
}
