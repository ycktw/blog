---
title: "Windows Optimization:Before We Start to Develope"
date: 2026-05-12
categories: [Notes, Windows]
tags: [github-pages, windows, notes, development]
---

| 類別 | 優化項目 | 操作指令 / 具體步驟 | 目的與效益 |
| --- | --- | --- | --- |
| 硬體防護 | 預留空間 (OP) |  在「磁碟管理」壓縮 C 槽，切出 30GB - 50GB 保持「未配置」| 提供 SSD 主控緩衝區，預防掉盤死鎖 |
| 硬體防護 | 關閉休眠 | 以管理員執行：powercfg -h off,刪除數 GB 的 hiberfil.sys | 釋放磁碟尾端佔用 |
| 系統 I/O | 停用 SysMain,services.msc > 找到 SysMain > 設為「已停用」並停止 | 減少系統在背景無意義地預載與讀寫檔案 |
| 系統 I/O | 關閉存取時間,以管理員執行：fsutil behavior set disablelastaccess 1 | 讀取檔案時不再寫入「上次存取時間」到 NTFS 表格|
| 系統 I/O | 商店自動更新,Microsoft Store > 設定 > 關閉「自動更新應用程式」| 避免 Windows 商店在背景無預警下載/安裝 App|
| 開發保護 | 搜尋索引排除,設定 > 搜尋 Windows > 排除資料夾 > 加入專案目錄 | 避免編譯時產生的巨量暫存檔被系統反覆索引 |
| 開發保護 | 防毒掃描排除,Windows 安全性 > 病毒與威脅防護 > 管理設定 > 排除項目 | 防止 Windows Defender 在編譯時同步掃描暫存檔 |
| 更新壓制 | 更新頻寬限制,設定 > Windows Update > 傳遞最佳化 > 進階 > 限制下載頻寬,將背景更新寫入變為「涓滴細流」| 避免塞爆 I/O|
| 更新壓制 | 手動更新原則,gpedit.msc > Windows Update > 設定自動更新 > 改為「選項 2」,將自動更新改為「通知我下載」| 拿回更新主控權 |
| 記憶體管理 | 釋放 Gradle,終端機執行：.\gradlew --stop | 釋放 Java (OpenJDK) 背景行程咬住的數 GB 記憶體 |