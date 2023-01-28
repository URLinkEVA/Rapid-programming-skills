function getClientInfo() {
    return {
      "name" : SV.T("[GT] Randomize Phoneme duration"),
      "author" : "Grog Tony",
      "versionNumber" : 1,
      "minEditorVersion" : 65540
    };
  }

function getTranslations(langCode) {
    if(langCode == "zh-cn") {
        return [
        ["[GT] Randomize Phoneme duration", "[GT] 随机化音素时间"],
        ["Randomize Phoneme duration", "随机化音素时间"],
        ["Offset range", "随机化强度"]
        ];
    }
    return [];
}

function randomRange(left, right){
    return left + (right - left) * Math.random();
}

function randomize(range){


    // Get the current selection, scope (group reference) and its target group.
    var selection = SV.getMainEditor().getSelection();
    var selectedNotes = selection.getSelectedNotes();
    
    for(var i = 0; i < selectedNotes.length; i ++) {
        var note = selectedNotes[i];
        var arr = [];
        for (var j = 0; j < 8; j ++){
            arr.push(randomRange(1 - range/100 , 1 + range/100));
        }
        note.setAttributes({
            "dur" : arr
        });
    }
}
function main() {
    var form = {
        "title"   : SV.T("Randomize Phoneme duration"),
        "message" : "",
        "buttons" : "OkCancel",
        "widgets" : [
          {
            "name"     : "range",
            "type"     : "Slider",
            "label"    : SV.T("Offset range"),
            "format"   : "%.0f",
            "minValue" : 0,
            "maxValue" : 80,
            "interval" : 1,
            "default"  : 50
          }
        ]
    };
    var results = SV.showCustomDialog(form);

    if(results.status)
        randomize(results.answers.range);
    
    SV.finish();
}
