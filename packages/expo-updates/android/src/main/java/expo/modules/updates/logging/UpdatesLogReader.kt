package expo.modules.updates.logging

import android.content.Context
import expo.modules.core.logging.PersistentFileLog
import expo.modules.updates.logging.UpdatesLogger.Companion.EXPO_UPDATES_LOGGING_TAG
import java.lang.Error
import java.util.*

/**
 * Class for reading expo-updates logs
 */
class UpdatesLogReader(
  private val context: Context
) {

  /**
   * Purge expo-updates logs older than the given date
   */
  fun purgeLogEntries(olderThan: Date, completionHandler: ((_: Error?) -> Unit)) {
    val epochTimestamp = olderThan.time
    persistentLog.filterEntries(
      { entryString -> entryStringLaterThanTimestamp(entryString, epochTimestamp) },
      {
        completionHandler(it)
      }
    )
  }

  /**
   Get expo-updates logs newer than the given date
   Returns a list of strings in the JSON format of UpdatesLogEntry
   */
  fun getLogEntries(newerThan: Date): List<String> {
    val epochTimestamp = newerThan.time
    return persistentLog.readEntries()
      .filter { entryString -> entryStringLaterThanTimestamp(entryString, epochTimestamp) }
  }

  private val persistentLog = PersistentFileLog(EXPO_UPDATES_LOGGING_TAG, context)

  private fun entryStringLaterThanTimestamp(entryString: String, timestamp: Long): Boolean {
    val entry = UpdatesLogEntry.create(entryString)
    return when (entry) {
      null -> false
      else -> {
        entry.timestamp >= timestamp
      }
    }
  }
}
