package com.example.nativefactorial

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.TextView
import com.example.nativefactorial.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        val utils = FactorialUtils()
        binding.button.setOnClickListener {
            FactorialUtils.calcFactorial(binding.editTextNumber.text.toString().toInt())
        }

    }



    /**
     * A native method that is implemented by the 'nativefactorial' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    companion object {

        private lateinit var binding: ActivityMainBinding

        // Used to load the 'nativefactorial' library on application startup.
        init {
            System.loadLibrary("nativefactorial")
        }
        @JvmStatic
        fun displayResult(num : Long)
        {
            binding.textView.text = num.toString()
        }
    }
}