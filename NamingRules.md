---
title: SyncKit Android/Kotlin Naming Rule
tags: syncvision, private, coding guide
disqus: hackmd
---

# 第一部分：核心原則 (IEC 62304 精神)

## 清晰優於簡潔 (Clarity over brevity)

> 在醫療軟體中，避免過度縮寫。calcTemp() 不如 calculateTemperature() 來得安全。

## 領域驅動 (Domain-Driven)

> 變數與類別名稱應反映醫療領域的實際意義，而非單純的技術術語。

## 單位明確 (Unit Indication)

> 涉及物理量（如時間、溫度、電壓）的變數，必須在名稱後綴標示單位。這能極大降低單位換算錯誤導致的潛在風險。

# 第二部分：具體命名規範 (Kotlin / Android)

## 1. 類別與介面 (Classes and Interfaces)

* 規則：使用大寫駝峰式（PascalCase）。

> 規範要求：名稱必須是名詞或名詞片語，清楚說明其職責。介面不需加 I 前綴（Kotlin 慣例）。

```kotlin
SyncKit 範例：
class TemperatureSensorManager (優)
class TempMgr (劣：過度縮寫)
interface CalibrationCallback (優)
```

## 2. 函式與方法 (Functions and Methods)

* 規則：使用小寫駝峰式（camelCase）。

> 規範要求：必須以動詞開頭，清楚描述行為。如果是布林值回傳的函式，應以 is, has, can 開頭。

```kotlin
SyncKit 範例：
fun initializeCamera()
fun isDeviceCalibrated(): Boolean
fun calculateSkinTemperature()
```

## 3. 變數與屬性 (Variables and Properties)

* 規則：使用小寫駝峰式（camelCase）。

> 規範要求：避免使用單一字母的變數（如 i, j），除非是在極短的迴圈內部。
> (關鍵) 物理量必須帶有單位後綴。

``` kotlin
SyncKit 範例：
val timeoutDelayMillis: Long = 5000L (優：標示了毫秒)
val timeout: Long = 5000L (劣：不知單位是秒還是毫秒)
var ambientTemperatureCelsius: Double (優)
val isCameraReady: Boolean
```

## 4. 常數 (Constants)

* 規則：使用全大寫字母並以底線分隔（SCREAMING_SNAKE_CASE）。

> 規範要求：僅適用於 const val 或沒有自訂 get() 的伴生物件（companion object）屬性。

```kotlin
SyncKit 範例：
const val MAX_RETRY_COUNT = 3
const val CALIBRATION_DEFAULT_OFFSET_CELSIUS = 1.5
```

## 5. 封裝與可見性後綴 (Encapsulation - Backing Properties)

* 規則：在 ViewModel 或封裝狀態時，內部可變狀態使用前綴底線 _，對外公開的不可變狀態則沒有底線。

```kotlin
SyncKit 範例：
private val _cameraStatus = MutableStateFlow(CameraState.IDLE)
val cameraStatus: StateFlow<CameraState> = _cameraStatus
```

## 6. Android UI 元件 (View Binding / Compose)

* XML Views (如果還有使用)：使用小寫加上底線，前綴為元件類型（例如：tv_temperature_display, btn_start_scan）。但在 Kotlin 程式碼中存取時，應轉換為 camelCase。

* Jetpack Compose (建議做法)：

> Composable 函式必須使用大寫駝峰式（PascalCase），且必須是名詞。

```kotlin
@Composable fun TemperatureDisplayCard(tempCelsius: Double)
```

## 7. 醫療特有詞彙與縮寫對照表

* 在 SDP 中，必須包含一份這類的對照表，以防止不同工程師對縮寫的解讀不同)

| Bad | Result | Note |
| --- | --- | --- |
| Temp | 禁用 | 應使用 Temperature |
| Cal | 禁用 | 應使用 Calibration |
| IR | 允許 | Infrared |
| ESD | 允許 | Electrostatic Discharge |
