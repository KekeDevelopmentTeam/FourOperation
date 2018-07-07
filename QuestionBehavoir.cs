using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class QuestionBehavoir : MonoBehaviour {

    // Use this for 


initialization
    public Button button;
    public int ans;
    public InputField input;
    public Text correctAns;
	void Start () {
     
	}
	
	// Update is called once per frame
	void Update () {
		
	}
    public void ShowAnswer()
    {
        correctAns.text = "正确答案：" + ans.ToString();
    }
}
